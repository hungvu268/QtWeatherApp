/****************************************************************************
** Meta object code from reading C++ file 'weatherdata.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/weatherdata.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weatherdata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN11WeatherDataE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN11WeatherDataE = QtMocHelpers::stringData(
    "WeatherData",
    "locationChanged",
    "",
    "temperatureChanged",
    "feelsLikeChanged",
    "humidityChanged",
    "windSpeedChanged",
    "windDirectionChanged",
    "conditionChanged",
    "conditionTextChanged",
    "timestampChanged",
    "conditionFromString",
    "WeatherCondition",
    "condition",
    "location",
    "temperature",
    "feelsLike",
    "humidity",
    "windSpeed",
    "windDirection",
    "conditionText",
    "timestamp",
    "iconSource",
    "Unknown",
    "Sunny",
    "Cloudy",
    "Rainy",
    "Snowy"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN11WeatherDataE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
      10,   86, // properties
       1,  136, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x06,   12 /* Public */,
       3,    0,   75,    2, 0x06,   13 /* Public */,
       4,    0,   76,    2, 0x06,   14 /* Public */,
       5,    0,   77,    2, 0x06,   15 /* Public */,
       6,    0,   78,    2, 0x06,   16 /* Public */,
       7,    0,   79,    2, 0x06,   17 /* Public */,
       8,    0,   80,    2, 0x06,   18 /* Public */,
       9,    0,   81,    2, 0x06,   19 /* Public */,
      10,    0,   82,    2, 0x06,   20 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      11,    1,   83,    2, 0x02,   21 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    0x80000000 | 12, QMetaType::QString,   13,

 // properties: name, type, flags, notifyId, revision
      14, QMetaType::QString, 0x00015103, uint(0), 0,
      15, QMetaType::Double, 0x00015103, uint(1), 0,
      16, QMetaType::Double, 0x00015103, uint(2), 0,
      17, QMetaType::Int, 0x00015103, uint(3), 0,
      18, QMetaType::Double, 0x00015103, uint(4), 0,
      19, QMetaType::QString, 0x00015103, uint(5), 0,
      13, QMetaType::Int, 0x00015003, uint(6), 0,
      20, QMetaType::QString, 0x00015103, uint(7), 0,
      21, QMetaType::QDateTime, 0x00015103, uint(8), 0,
      22, QMetaType::QString, 0x00015001, uint(6), 0,

 // enums: name, alias, flags, count, data
      12,   12, 0x0,    5,  141,

 // enum data: key, value
      23, uint(WeatherData::Unknown),
      24, uint(WeatherData::Sunny),
      25, uint(WeatherData::Cloudy),
      26, uint(WeatherData::Rainy),
      27, uint(WeatherData::Snowy),

       0        // eod
};

Q_CONSTINIT const QMetaObject WeatherData::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN11WeatherDataE.offsetsAndSizes,
    qt_meta_data_ZN11WeatherDataE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN11WeatherDataE_t,
        // property 'location'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'temperature'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'feelsLike'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'humidity'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'windSpeed'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'windDirection'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'condition'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'conditionText'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'timestamp'
        QtPrivate::TypeAndForceComplete<QDateTime, std::true_type>,
        // property 'iconSource'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // enum 'WeatherCondition'
        QtPrivate::TypeAndForceComplete<WeatherData::WeatherCondition, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<WeatherData, std::true_type>,
        // method 'locationChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'temperatureChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'feelsLikeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'humidityChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'windSpeedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'windDirectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'conditionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'conditionTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'timestampChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'conditionFromString'
        QtPrivate::TypeAndForceComplete<WeatherCondition, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void WeatherData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<WeatherData *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->locationChanged(); break;
        case 1: _t->temperatureChanged(); break;
        case 2: _t->feelsLikeChanged(); break;
        case 3: _t->humidityChanged(); break;
        case 4: _t->windSpeedChanged(); break;
        case 5: _t->windDirectionChanged(); break;
        case 6: _t->conditionChanged(); break;
        case 7: _t->conditionTextChanged(); break;
        case 8: _t->timestampChanged(); break;
        case 9: { WeatherCondition _r = _t->conditionFromString((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< WeatherCondition*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (WeatherData::*)();
            if (_q_method_type _q_method = &WeatherData::locationChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (WeatherData::*)();
            if (_q_method_type _q_method = &WeatherData::temperatureChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (WeatherData::*)();
            if (_q_method_type _q_method = &WeatherData::feelsLikeChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (WeatherData::*)();
            if (_q_method_type _q_method = &WeatherData::humidityChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (WeatherData::*)();
            if (_q_method_type _q_method = &WeatherData::windSpeedChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (WeatherData::*)();
            if (_q_method_type _q_method = &WeatherData::windDirectionChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _q_method_type = void (WeatherData::*)();
            if (_q_method_type _q_method = &WeatherData::conditionChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _q_method_type = void (WeatherData::*)();
            if (_q_method_type _q_method = &WeatherData::conditionTextChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _q_method_type = void (WeatherData::*)();
            if (_q_method_type _q_method = &WeatherData::timestampChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->location(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->temperature(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->feelsLike(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->humidity(); break;
        case 4: *reinterpret_cast< double*>(_v) = _t->windSpeed(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->windDirection(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->conditionInt(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->conditionText(); break;
        case 8: *reinterpret_cast< QDateTime*>(_v) = _t->timestamp(); break;
        case 9: *reinterpret_cast< QString*>(_v) = _t->iconSource(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLocation(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setTemperature(*reinterpret_cast< double*>(_v)); break;
        case 2: _t->setFeelsLike(*reinterpret_cast< double*>(_v)); break;
        case 3: _t->setHumidity(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setWindSpeed(*reinterpret_cast< double*>(_v)); break;
        case 5: _t->setWindDirection(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setConditionInt(*reinterpret_cast< int*>(_v)); break;
        case 7: _t->setConditionText(*reinterpret_cast< QString*>(_v)); break;
        case 8: _t->setTimestamp(*reinterpret_cast< QDateTime*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *WeatherData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WeatherData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN11WeatherDataE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WeatherData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void WeatherData::locationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WeatherData::temperatureChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void WeatherData::feelsLikeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void WeatherData::humidityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void WeatherData::windSpeedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void WeatherData::windDirectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void WeatherData::conditionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void WeatherData::conditionTextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void WeatherData::timestampChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
