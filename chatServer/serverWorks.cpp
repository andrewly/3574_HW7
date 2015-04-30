#include "ServerWorks.h"

explicit ServerWorks()
{
	int numbMemebers = 0;
	
	//connect(client,SIGNAL(checkServer(void), QString)),this,SLOT((QString)));
	//connect(client,SIGNAL(exit(void), QString)),this,SLOT(exitClient(QString)));
	//connect(client,SIGNAL(sending(QString, QString)),this,SLOT(gotMessage(QString, QString, QString));

}

~ServerWorks()
{

}
	
void checkClient(QString name)
{
	for (int i = 0, i < numbMembers, i++)
	{
		if (members[i] == name)
		{
			return 0;			
		}
		else
			return 1;
	}
}


void gotMessage(QString message, QString sender, QString target);
{
	QString home = "General Chat"; 
	if (target == home)
	{
		textEdit.append( "client " + sender + ": " + message);
	}
	else
	{
		textEdit.append( "client " + sender + " sent private chat to " + target + ": " + message);
	}
}

void getClient(QString name);
{
	
	if (checkClient(name))
	{
		textEdit.append( "client " + name +": Has 	joined the chat session");
	
		members[numbMembers] = name;
		numbMembers++;
		
		emit serverOn( 1, 1);
	}
	else
		emit serverOn(1, 0);
	
}

void exitClient(QString name)
{
		for (int i = 0, i < numbMembers, i++)
	{
		if (members[i] == name)
		{
			for (int j = i, j < numbMembers, i++)
				{
					members[j] = members[j+1];
				}			
		}
	}
	
	members[numbMembers+1] = name;
	
	textEdit.append( "client " + name +": Has exited the chat session");
	numbMembers--;

}