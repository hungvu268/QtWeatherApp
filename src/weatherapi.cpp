#include "weatherapi.h"
#include <QUrlQuery>
#include <QtMath>

WeatherAPI::WeatherAPI(QObject *parent)
    : QObject(parent),
    m_networkManager(new QNetworkAccessManager(this)),
    m_apiKey("96d813439905e612339e195a31fc5212"), // Replace with your actual OpenWeatherMap API key
    m_currentWeather(new WeatherData(this)),
    m_loading(false)
{
    connect(m_networkManager, &QNetworkAccessManager::finished,
            this, &WeatherAPI::handleNetworkReply);
}

WeatherAPI::~WeatherAPI()
{
    // WeatherData object will be deleted automatically as it has this as parent
}

WeatherData* WeatherAPI::currentWeather() const
{
    return m_currentWeather;
}

bool WeatherAPI::loading() const
{
    return m_loading;
}

QString WeatherAPI::errorMessage() const
{
    return m_errorMessage;
}

void WeatherAPI::setApiKey(const QString &apiKey)
{
    m_apiKey = apiKey;
}

void WeatherAPI::getCurrentWeather(const QString &city)
{
    if (city.isEmpty()) {
        setErrorMessage("City name cannot be empty");
        return;
    }

    if (m_apiKey.isEmpty() || m_apiKey == "YOUR_API_KEY") {
        setErrorMessage("API key not set. Please set a valid OpenWeatherMap API key.");
        return;
    }

    setLoading(true);
    setErrorMessage("");

    QUrl url(API_BASE_URL);
    QUrlQuery query;

    query.addQueryItem("q", city);
    query.addQueryItem("units", "metric"); // Use metric units (Celsius)
    query.addQueryItem("appid", m_apiKey);

    url.setQuery(query);

    QNetworkRequest request(url);
    m_networkManager->get(request);
}

void WeatherAPI::getCurrentWeatherByCoords(double latitude, double longitude)
{
    if (m_apiKey.isEmpty() || m_apiKey == "YOUR_API_KEY") {
        setErrorMessage("API key not set. Please set a valid OpenWeatherMap API key.");
        return;
    }

    setLoading(true);
    setErrorMessage("");

    QUrl url(API_BASE_URL);
    QUrlQuery query;

    query.addQueryItem("lat", QString::number(latitude));
    query.addQueryItem("lon", QString::number(longitude));
    query.addQueryItem("units", "metric"); // Use metric units (Celsius)
    query.addQueryItem("appid", m_apiKey);

    url.setQuery(query);

    QNetworkRequest request(url);
    m_networkManager->get(request);
}

void WeatherAPI::handleNetworkReply(QNetworkReply *reply)
{
    setLoading(false);

    if (reply->error() != QNetworkReply::NoError) {
        setErrorMessage("Network error: " + reply->errorString());
        reply->deleteLater();
        return;
    }

    QByteArray responseData = reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);

    if (jsonResponse.isNull() || !jsonResponse.isObject()) {
        setErrorMessage("Invalid response format");
        reply->deleteLater();
        return;
    }

    parseWeatherData(jsonResponse);
    reply->deleteLater();
}

void WeatherAPI::parseWeatherData(const QJsonDocument &jsonResponse)
{
    QJsonObject rootObj = jsonResponse.object();

    // Set location
    if (rootObj.contains("name")) {
        m_currentWeather->setLocation(rootObj["name"].toString());
    }

    // Set temperature data
    if (rootObj.contains("main") && rootObj["main"].isObject()) {
        QJsonObject mainObj = rootObj["main"].toObject();

        if (mainObj.contains("temp")) {
            m_currentWeather->setTemperature(mainObj["temp"].toDouble());
        }

        if (mainObj.contains("feels_like")) {
            m_currentWeather->setFeelsLike(mainObj["feels_like"].toDouble());
        }

        if (mainObj.contains("humidity")) {
            m_currentWeather->setHumidity(mainObj["humidity"].toInt());
        }
    }

    // Set wind data
    if (rootObj.contains("wind") && rootObj["wind"].isObject()) {
        QJsonObject windObj = rootObj["wind"].toObject();

        if (windObj.contains("speed")) {
            m_currentWeather->setWindSpeed(windObj["speed"].toDouble());
        }

        if (windObj.contains("deg")) {
            double degrees = windObj["deg"].toDouble();
            QStringList directions = {"N", "NE", "E", "SE", "S", "SW", "W", "NW", "N"};
            int index = qRound(degrees / 45.0);
            if (index >= 0 && index < directions.size()) {
                m_currentWeather->setWindDirection(directions[index]);
            }
        }
    }

    // Set weather condition
    if (rootObj.contains("weather") && rootObj["weather"].isArray()) {
        QJsonArray weatherArray = rootObj["weather"].toArray();

        if (!weatherArray.isEmpty()) {
            QJsonObject weatherObj = weatherArray.first().toObject();

            if (weatherObj.contains("description")) {
                QString description = weatherObj["description"].toString();
                m_currentWeather->setConditionText(description);
                m_currentWeather->setCondition(WeatherData::conditionFromString(description));
            }
        }
    }

    // Set timestamp
    m_currentWeather->setTimestamp(QDateTime::currentDateTime());

    // Emit signal that weather data has changed
    emit weatherDataChanged();
}

void WeatherAPI::setLoading(bool loading)
{
    if (m_loading != loading) {
        m_loading = loading;
        emit loadingChanged();
    }
}

void WeatherAPI::setErrorMessage(const QString &message)
{
    if (m_errorMessage != message) {
        m_errorMessage = message;
        emit errorOccurred(message);
    }
}
