#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <QObject>
#include <QString>
#include <QDateTime>

class WeatherData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString location READ location WRITE setLocation NOTIFY locationChanged)
    Q_PROPERTY(double temperature READ temperature WRITE setTemperature NOTIFY temperatureChanged)
    Q_PROPERTY(double feelsLike READ feelsLike WRITE setFeelsLike NOTIFY feelsLikeChanged)
    Q_PROPERTY(int humidity READ humidity WRITE setHumidity NOTIFY humidityChanged)
    Q_PROPERTY(double windSpeed READ windSpeed WRITE setWindSpeed NOTIFY windSpeedChanged)
    Q_PROPERTY(QString windDirection READ windDirection WRITE setWindDirection NOTIFY windDirectionChanged)
    Q_PROPERTY(int condition READ conditionInt WRITE setConditionInt NOTIFY conditionChanged)
    Q_PROPERTY(QString conditionText READ conditionText WRITE setConditionText NOTIFY conditionTextChanged)
    Q_PROPERTY(QDateTime timestamp READ timestamp WRITE setTimestamp NOTIFY timestampChanged)
    Q_PROPERTY(QString iconSource READ iconSource NOTIFY conditionChanged)

public:
    enum WeatherCondition {
        Unknown = 0,
        Sunny = 1,
        Cloudy = 2,
        Rainy = 3,
        Snowy = 4
    };
    Q_ENUM(WeatherCondition)

    explicit WeatherData(QObject *parent = nullptr);

    // Getters
    QString location() const;
    double temperature() const;
    double feelsLike() const;
    int humidity() const;
    double windSpeed() const;
    QString windDirection() const;
    WeatherCondition condition() const;
    int conditionInt() const;
    QString conditionText() const;
    QDateTime timestamp() const;
    QString iconSource() const;

    // Setters
    void setLocation(const QString &location);
    void setTemperature(double temperature);
    void setFeelsLike(double feelsLike);
    void setHumidity(int humidity);
    void setWindSpeed(double windSpeed);
    void setWindDirection(const QString &windDirection);
    void setCondition(WeatherCondition condition);
    void setConditionInt(int condition);
    void setConditionText(const QString &conditionText);
    void setTimestamp(const QDateTime &timestamp);

    // Helper methods
    Q_INVOKABLE static WeatherCondition conditionFromString(const QString &condition);

signals:
    void locationChanged();
    void temperatureChanged();
    void feelsLikeChanged();
    void humidityChanged();
    void windSpeedChanged();
    void windDirectionChanged();
    void conditionChanged();
    void conditionTextChanged();
    void timestampChanged();

private:
    QString m_location;
    double m_temperature;
    double m_feelsLike;
    int m_humidity;
    double m_windSpeed;
    QString m_windDirection;
    WeatherCondition m_condition;
    QString m_conditionText;
    QDateTime m_timestamp;
};

#endif // WEATHERDATA_H
