#ifndef WEATHERAPI_H
#define WEATHERAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "weatherdata.h"

class WeatherAPI : public QObject
{
    Q_OBJECT

    Q_PROPERTY(WeatherData* currentWeather READ currentWeather NOTIFY weatherDataChanged)
    Q_PROPERTY(bool loading READ loading NOTIFY loadingChanged)
    Q_PROPERTY(QString errorMessage READ errorMessage NOTIFY errorOccurred)

public:
    explicit WeatherAPI(QObject *parent = nullptr);
    ~WeatherAPI();

    // Property getters
    WeatherData* currentWeather() const;
    bool loading() const;
    QString errorMessage() const;

    // API methods
    Q_INVOKABLE void getCurrentWeather(const QString &city);
    Q_INVOKABLE void getCurrentWeatherByCoords(double latitude, double longitude);
    Q_INVOKABLE void setApiKey(const QString &apiKey);

signals:
    // Signal emitted when weather data is successfully retrieved
    void weatherDataChanged();

    // Signal emitted when there's an error
    void errorOccurred(const QString &errorMessage);

    // Signal emitted when loading state changes
    void loadingChanged();

private slots:
    // Handle API response
    void handleNetworkReply(QNetworkReply *reply);

private:
    QNetworkAccessManager *m_networkManager;
    QString m_apiKey;
    WeatherData *m_currentWeather;
    bool m_loading;
    QString m_errorMessage;

    // OpenWeatherMap API base URL
    const QString API_BASE_URL = "https://api.openweathermap.org/data/2.5/weather";

    // Parse JSON response
    void parseWeatherData(const QJsonDocument &jsonResponse);

    // Set loading state
    void setLoading(bool loading);

    // Set error message
    void setErrorMessage(const QString &message);
};

#endif // WEATHERAPI_H
