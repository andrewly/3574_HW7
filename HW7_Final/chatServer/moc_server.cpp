/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Server_t {
    QByteArrayData data[16];
    char stringdata[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Server_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Server_t qt_meta_stringdata_Server = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 22),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 16),
QT_MOC_LITERAL(4, 48, 24),
QT_MOC_LITERAL(5, 73, 14),
QT_MOC_LITERAL(6, 88, 8),
QT_MOC_LITERAL(7, 97, 22),
QT_MOC_LITERAL(8, 120, 16),
QT_MOC_LITERAL(9, 137, 17),
QT_MOC_LITERAL(10, 155, 9),
QT_MOC_LITERAL(11, 165, 16),
QT_MOC_LITERAL(12, 182, 6),
QT_MOC_LITERAL(13, 189, 14),
QT_MOC_LITERAL(14, 204, 16),
QT_MOC_LITERAL(15, 221, 17)
    },
    "Server\0startStopButtonClicked\0\0"
    "keyButtonClicked\0certificateButtonClicked\0"
    "keyFileChanged\0filename\0certificateFileChanged\0"
    "acceptConnection\0handshakeComplete\0"
    "sslErrors\0QList<QSslError>\0errors\0"
    "receiveMessage\0connectionClosed\0"
    "connectionFailure\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Server[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x09,
       3,    0,   70,    2, 0x09,
       4,    0,   71,    2, 0x09,
       5,    1,   72,    2, 0x09,
       7,    1,   75,    2, 0x09,
       8,    0,   78,    2, 0x09,
       9,    0,   79,    2, 0x09,
      10,    1,   80,    2, 0x09,
      13,    0,   83,    2, 0x09,
      14,    0,   84,    2, 0x09,
      15,    0,   85,    2, 0x09,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Server *_t = static_cast<Server *>(_o);
        switch (_id) {
        case 0: _t->startStopButtonClicked(); break;
        case 1: _t->keyButtonClicked(); break;
        case 2: _t->certificateButtonClicked(); break;
        case 3: _t->keyFileChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->certificateFileChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->acceptConnection(); break;
        case 6: _t->handshakeComplete(); break;
        case 7: _t->sslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        case 8: _t->receiveMessage(); break;
        case 9: _t->connectionClosed(); break;
        case 10: _t->connectionFailure(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            }
            break;
        }
    }
}

const QMetaObject Server::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Server.data,
      qt_meta_data_Server,  qt_static_metacall, 0, 0}
};


const QMetaObject *Server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Server::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Server.stringdata))
        return static_cast<void*>(const_cast< Server*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
