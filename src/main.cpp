#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFont>
#include <QFontDatabase>
#include <QDir>
#include <QDebug>
#include "weatherapi.h"
#include "weatherdata.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Set application information
    QGuiApplication::setApplicationName("Qt Weather App");
    QGuiApplication::setOrganizationName("YourOrganization");
    QGuiApplication::setApplicationVersion("1.0");

    // Create weather API instance
    WeatherAPI *weatherApi = new WeatherAPI(&app);

    // Create QML engine
    QQmlApplicationEngine engine;

    // Debug information
    qDebug() << "Current working directory:" << QDir::currentPath();
    qDebug() << "QML import paths:" << engine.importPathList();

    // Register C++ types to QML
    qmlRegisterType<WeatherData>("com.example.weather", 1, 0, "WeatherData");

    // Expose C++ objects to QML
    engine.rootContext()->setContextProperty("weatherApi", weatherApi);

    // Load main QML file with absolute path for debugging
    QString qmlPath = "qrc:/qml/main.qml";
    qDebug() << "Loading QML from:" << qmlPath;

    const QUrl url(qmlPath);

    // Connect to check for errors
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                         if (!obj && url == objUrl) {
                             qDebug() << "Failed to create QML object from:" << url;
                             QCoreApplication::exit(-1);
                         } else if (obj && url == objUrl) {
                             qDebug() << "Successfully created QML object";
                         }
                     }, Qt::QueuedConnection);

    engine.load(url);

    // Check if we have an error
    if (engine.rootObjects().isEmpty()) {
        qDebug() << "No root objects created. QML loading failed!";
        return -1;
    }

    return app.exec();
}
