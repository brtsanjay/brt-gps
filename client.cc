#include "client.hh"
#include <iostream>
#include <QTcpSocket>

Client::Client( const QString& hostName, const quint16& port, QWidget* parent ) :
	QWidget( parent ) {
	tcpSocket = new QTcpSocket;
	tcpSocket->connectToHost( hostName, port );

	QObject::connect( tcpSocket, SIGNAL( connected() ), this, SLOT( ConnectionEstablished() ) );
	QObject::connect( tcpSocket, SIGNAL( readyRead() ), this, SLOT( NewDataAvailable() ) );
}

void Client::ConnectionEstablished() {
	std::cout << "Connection established!" << std::endl;
}

void Client::NewDataAvailable() {
//	std::cout << "New data available!" << std::endl;
	qint64 num_bytes = tcpSocket->readLine( data, sizeof( data ) );
	std::cout << "Size (in bytes): " << num_bytes << std::endl << "Data: " << data << std::endl;
}
