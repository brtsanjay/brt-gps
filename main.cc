#include "client.hh"
#include <QApplication>

int main( int argc, char** argv ) {
	QApplication app( argc, argv );
	
	Client client;
//	Client client( "192.168.10.2", 4361 );

	return app.exec();
}

