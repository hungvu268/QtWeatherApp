#include "weatherdata.h"

WeatherData::WeatherData(QObject *parent)
    : QObject(parent),
    m_temperature(0.0),
    m_feelsLike(0.0),
    m_humidity(0),
    m_windSpeed(0.0),
    m_condition(Unknown),
    m_timestamp(QDateTime::currentDateTime())
{
}

QString WeatherData::location() const
{
    return m_location;
}

double WeatherData::temperature() const
{
    return m_temperature;
}

double WeatherData::feelsLike() const
{
    return m_feelsLike;
}

int WeatherData::humidity() const
{
    return m_humidity;
}

double WeatherData::windSpeed() const
{
    return m_windSpeed;
}

QString WeatherData::windDirection() const
{
    return m_windDirection;
}

WeatherData::WeatherCondition WeatherData::condition() const
{
    return m_condition;
}

int WeatherData::conditionInt() const
{
    return static_cast<int>(m_condition);
}

QString WeatherData::conditionText() const
{
    return m_conditionText;
}

QDateTime WeatherData::timestamp() const
{
    return m_timestamp;
}

QString WeatherData::iconSource() const
{
    switch (m_condition) {
    case Sunny:
        return "qrc:/icons/sunny.png";
    case Cloudy:
        return "qrc:/icons/cloudy.png";
    case Rainy:
        return "qrc:/icons/rainy.png";
    case Snowy:
        return "qrc:/icons/snowy.png";
    default:
        return "qrc:/icons/cloudy.png"; // Default icon
    }
}

void WeatherData::setLocation(const QString &location)
{
    if (m_location != location) {
        m_location = location;
        emit locationChanged();
    }
}

void WeatherData::setTemperature(double temperature)
{
    if (!qFuzzyCompare(m_temperature, temperature)) {
        m_temperature = temperature;
        emit temperatureChanged();
    }
}

void WeatherData::setFeelsLike(double feelsLike)
{
    if (!qFuzzyCompare(m_feelsLike, feelsLike)) {
        m_feelsLike = feelsLike;
        emit feelsLikeChanged();
    }
}

void WeatherData::setHumidity(int humidity)
{
    if (m_humidity != humidity) {
        m_humidity = humidity;
        emit humidityChanged();
    }
}

void WeatherData::setWindSpeed(double windSpeed)
{
    if (!qFuzzyCompare(m_windSpeed, windSpeed)) {
        m_windSpeed = windSpeed;
        emit windSpeedChanged();
    }
}

void WeatherData::setWindDirection(const QString &windDirection)
{
    if (m_windDirection != windDirection) {
        m_windDirection = windDirection;
        emit windDirectionChanged();
    }
}

void WeatherData::setCondition(WeatherCondition condition)
{
    if (m_condition != condition) {
        m_condition = condition;
        emit conditionChanged();
    }
}

void WeatherData::setConditionInt(int condition)
{
    setCondition(static_cast<WeatherCondition>(condition));
}

void WeatherData::setConditionText(const QString &conditionText)
{
    if (m_conditionText != conditionText) {
        m_conditionText = conditionText;
        emit conditionTextChanged();
    }
}

void WeatherData::setTimestamp(const QDateTime &timestamp)
{
    if (m_timestamp != timestamp) {
        m_timestamp = timestamp;
        emit timestampChanged();
    }
}

WeatherData::WeatherCondition WeatherData::conditionFromString(const QString &condition)
{
    QString lowered = condition.toLower();

    if (lowered.contains("clear") || lowered.contains("sunny"))
        return Sunny;
    else if (lowered.contains("cloud") || lowered.contains("overcast"))
        return Cloudy;
    else if (lowered.contains("rain") || lowered.contains("drizzle") || lowered.contains("shower"))
        return Rainy;
    else if (lowered.contains("snow") || lowered.contains("blizzard") || lowered.contains("ice"))
        return Snowy;
    else
        return Unknown;
}
