#ifndef CLIENT_HH
#define CLIENT_HH

#include <QWidget>
#include <QTcpSocket>

class Client : public QWidget {
	Q_OBJECT
public:
	Client( const QString& hostName = "192.168.10.2", const quint16& port = 4361, QWidget* parent = 0 );
private:
	QTcpSocket *tcpSocket;
	char data[ 1024 ];
private slots:
	void ConnectionEstablished();
	void NewDataAvailable();
};

#endif // CLIENT_HH
