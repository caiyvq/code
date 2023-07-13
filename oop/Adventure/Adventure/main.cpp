#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;

class room
{
public:
	void setName();//���÷�������Ϊroom(x,y,z)��lobby��
	//void setExit();
	void setMonster();//���ù���
	bool getMonster();//�ж��Ƿ��й���
	void setPrincess();//���ù���
	void foundPrincess();//���߹���
	bool getPrincess();//�ж��Ƿ��й���
	void info();//������Ϣ
	int getLocation();//��ȡ�����
	void initial(int no);//��ʼ�����䣬noΪ�����
	//��ȡ��������
	int getx();
	int gety();
	int getz();
protected:
	string name;//������
	//��������
	int x=0;
	int y=0;
	int z=0;
	//bool east = 0;
	//bool west = 0;
	//bool north = 0;
	//bool south = 0;
	//bool up = 0;
	//bool down = 0;
	bool monster = 0;//���޹���
	bool princess = 0;//���޹���
};
class castle
{
public:
	void initial();//��ʼ������
	vector<room>rooms;//�����ȫ������
	int size=27;
};
int main()
{
	//�������������
	cout << "You are now in the lobby of the castle. What you need to do is to find the princess who is prisoned in the castle by a monster, and take her out." << endl;
	cout << "This task is dangerous. If you are caught by the monster, you have no way to survive." << endl;
	cout << "So if you are ready to save the princess, you can press the enter key to continue.Or you can just click the exit button to leave." << endl;
	system("pause");
	srand(time(0));
	//�Ƿ�������������
	bool meetMonster = 0;
	bool meetPrincess = 0;
	castle myCastle;
	//��ʼ��
	myCastle.initial();
	//�Ƿ�����˹�����ж�
	bool started = 0;
	//��ǰλ��
	int location = 0;
	//��ǰ����
	room currentRoom = myCastle.rooms[location];
	//̽������
	while (1)
	{
		//����������û���ҵ�������ȴ�ٴλص���lobby��������Ҫ��������
		if (meetPrincess == 0 && currentRoom.getLocation() == 0&&started==1)
		{
			cout << "Hey! You haven't found the princess yet.Do you want to run away? Come on, let's continue." << endl;
		}
		//�ҵ��������ص���lobby�������뿪��
		if (meetPrincess ==1 && currentRoom.getLocation() == 0)
		{
			break;
		}
	loop:
		//����������Ϣ
		currentRoom.info();
		//�����й����û��
		if (currentRoom.getMonster())
		{
			meetMonster = 1;
			break;
		}
		//�����й�����������˹���
		if (currentRoom.getPrincess())
		{
			meetPrincess = 1;
			myCastle.rooms[location].foundPrincess();
			currentRoom.foundPrincess();
		}
		//���������һ��
		string order;
		getline(cin,order);
		if ((order == "go east"||order=="east"||order=="e")&&(currentRoom.getx() == 0||currentRoom.getx()==1))
		{
			//���ߵȼ��ڷ���ż�1
			currentRoom = myCastle.rooms[++location];
		}
		else if ((order == "go west" || order == "west" ||order == "w") && (currentRoom.getx() == 2 || currentRoom.getx() == 1))
		{
			//�����ߵȼ��ڷ���ż�1
			currentRoom = myCastle.rooms[--location];
		}
		else if ((order == "go north" || order == "north" || order == "n") && (currentRoom.gety() == 0 || currentRoom.gety() == 1))
		{
			//���ߵȼ��ڷ���ż�3
			location += 3;
			currentRoom = myCastle.rooms[location];
		}
		else if ((order == "go south" || order == "south" || order == "s") && (currentRoom.gety() == 2 || currentRoom.gety() == 1))
		{
			//�����ߵȼ��ڷ���ż�3
			location -= 3;
			currentRoom = myCastle.rooms[location];
		}
		else if ((order == "go up" || order == "up" || order == "u") && (currentRoom.getz() == 0 || currentRoom.getz() == 1))
		{
			//��¥�ȼ��ڷ���ż�9
			location += 9;
			currentRoom = myCastle.rooms[location];
		}
		else if ((order == "go down" || order == "down" || order == "d") && (currentRoom.getz() == 2 || currentRoom.getz() == 1))
		{
			//��¥�ȼ��ڷ���ż�9
			location -= 9;
			currentRoom = myCastle.rooms[location];
		}
		else
		{
			//���������ָ��
			cout << "Invalid order!" << endl;
			// goto����ֹ�������������������������˴���ָ�������ȴ�жϳ����Ǵӹ����ڻص�����
			goto loop;
		}
		started = 1;
	}
	//�˳�ѭ����������Ϊ����������߾ȳ���������������ж�
	if (meetMonster == 0)
	{
		cout << "Congradulation!You secured the princess successfully!";
	}
	return 0;
}

void room::setName()
{
	if (x == 0 && y == 0&&z==0)
		name = "lobby";
	else
	{
		name = "room(";
		name += x+'0';
		name += ",";
		name += y+'0';
		name += ",";
		name += z+'0';
		name += ")";
	}
}
//void room::setExit()
//{
//	switch (x)
//	{
//	case 0:east = 1; break;
//	case 1:east = 1; west = 1; break;
//	case 2:west = 1; break;
//	}
//	switch (y)
//	{
//	case 0:north = 1; break;
//	case 1:north = 1; south = 1; break;
//	case 2:south = 1; break;
//	}
//	switch (z)
//	{
//	case 0:up = 1; break;
//	case 1:up = 1; down = 1; break;
//	case 2:down = 1; break;
//	}
//}
void room::setMonster()
{
	monster = 1;
}
bool room::getMonster()
{
	return monster;
}
void room::setPrincess()
{
	princess = 1;
}
bool room::getPrincess()
{
	return princess;
}
void room::foundPrincess()
{
	princess = 0;
}
void room::initial(int no)
{
	//���磺no=16,��x=1,y=2,z=1,��������3����
	x = no % 3;
	y = no / 3 % 3;
	z = no / 3 / 3 % 3;
	setName();
	//setExit();
}
void room::info()
{
	if (monster)
	{
		cout << "Nope, the monster in this room!"<<endl<<"You fight, and you died..."<<endl<<"GAME OVER..."<<endl;
		return;
	}
	if (princess)
	{
		cout << "Ohhh,you find that the princess is in this room!" << endl;
		system("pause");
		cout << "Princess: Oh, my hero! You come to secure me! Thank you!" << endl;
		system("pause");
		cout << "Player: My princess, I won't let the monster hurt you anymore! I will take you out right now. Let's go!" << endl;
		system("pause");
		cout << "Now you need to secure the princess out of this castle!"<<endl;
	}
	else
		cout << "Welcom to the room : " << name << "." << endl;
	cout<< "Here are the exits : ";
	//���ݷ��������жϳ������
	switch (x)
	{
	case 0:cout<<"east "; break;
	case 1:cout<<"east west "; break;
	case 2:cout<<"west "; break;
	}
	switch (y)
	{
	case 0:cout << "north "; break;
	case 1:cout << "north south "; break;
	case 2:cout << "south "; break;
	}
	switch (z)
	{
	case 0:cout << "up "; break;
	case 1:cout << "up down "; break;
	case 2:cout << "down "; break;
	}
	cout <<endl<<"You can choose one exit to continue. For example: go east."<< endl;
	cout << "Your choice is :" << endl;
}
int room::getLocation()
{
	//����������걾������ʮ�����������ƵĹ�ϵ
	return z * 9 + y * 3 + x;
}
int room::getx()
{
	return x;
}
int room::gety()
{
	return y;
}
int room::getz()
{
	return z;
}
void castle::initial()
{
	//���ָ������͹������ɵķ���
	int monster = rand() % 27;
	while (monster == 0)
		monster = rand() % 27;
	int princess = rand() % 27;
	while (princess == monster||princess==0)
		princess = rand() % 27;
	for (int i = 0; i < size; i++)
	{
		room newRoom;
		newRoom.initial(i);
		if (i == monster)
			newRoom.setMonster();
		if (i == princess)
			newRoom.setPrincess();
		rooms.push_back(newRoom);
	}
}