#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;

class room
{
public:
	void setName();//设置房间名字为room(x,y,z)或lobby。
	//void setExit();
	void setMonster();//放置怪物
	bool getMonster();//判断是否有怪物
	void setPrincess();//放置公主
	void foundPrincess();//带走公主
	bool getPrincess();//判断是否有公主
	void info();//给出信息
	int getLocation();//获取房间号
	void initial(int no);//初始化房间，no为房间号
	//获取房间坐标
	int getx();
	int gety();
	int getz();
protected:
	string name;//房间名
	//房间坐标
	int x=0;
	int y=0;
	int z=0;
	//bool east = 0;
	//bool west = 0;
	//bool north = 0;
	//bool south = 0;
	//bool up = 0;
	//bool down = 0;
	bool monster = 0;//有无怪物
	bool princess = 0;//有无公主
};
class castle
{
public:
	void initial();//初始化宫殿
	vector<room>rooms;//宫殿的全部房间
	int size=27;
};
int main()
{
	//背景与任务介绍
	cout << "You are now in the lobby of the castle. What you need to do is to find the princess who is prisoned in the castle by a monster, and take her out." << endl;
	cout << "This task is dangerous. If you are caught by the monster, you have no way to survive." << endl;
	cout << "So if you are ready to save the princess, you can press the enter key to continue.Or you can just click the exit button to leave." << endl;
	system("pause");
	srand(time(0));
	//是否见过公主或怪物
	bool meetMonster = 0;
	bool meetPrincess = 0;
	castle myCastle;
	//初始化
	myCastle.initial();
	//是否进入了宫殿的判断
	bool started = 0;
	//当前位置
	int location = 0;
	//当前房间
	room currentRoom = myCastle.rooms[location];
	//探索宫殿
	while (1)
	{
		//进入过宫殿，还没有找到公主，却再次回到的lobby，你是想要逃跑了吗？
		if (meetPrincess == 0 && currentRoom.getLocation() == 0&&started==1)
		{
			cout << "Hey! You haven't found the princess yet.Do you want to run away? Come on, let's continue." << endl;
		}
		//找到公主并回到了lobby，可以离开了
		if (meetPrincess ==1 && currentRoom.getLocation() == 0)
		{
			break;
		}
	loop:
		//给出房间信息
		currentRoom.info();
		//房间有怪物，你没了
		if (currentRoom.getMonster())
		{
			meetMonster = 1;
			break;
		}
		//房间有公主，你带走了公主
		if (currentRoom.getPrincess())
		{
			meetPrincess = 1;
			myCastle.rooms[location].foundPrincess();
			currentRoom.foundPrincess();
		}
		//输入你的下一步
		string order;
		getline(cin,order);
		if ((order == "go east"||order=="east"||order=="e")&&(currentRoom.getx() == 0||currentRoom.getx()==1))
		{
			//向东走等价于房间号加1
			currentRoom = myCastle.rooms[++location];
		}
		else if ((order == "go west" || order == "west" ||order == "w") && (currentRoom.getx() == 2 || currentRoom.getx() == 1))
		{
			//向西走等价于房间号减1
			currentRoom = myCastle.rooms[--location];
		}
		else if ((order == "go north" || order == "north" || order == "n") && (currentRoom.gety() == 0 || currentRoom.gety() == 1))
		{
			//向北走等价于房间号加3
			location += 3;
			currentRoom = myCastle.rooms[location];
		}
		else if ((order == "go south" || order == "south" || order == "s") && (currentRoom.gety() == 2 || currentRoom.gety() == 1))
		{
			//向南走等价于房间号减3
			location -= 3;
			currentRoom = myCastle.rooms[location];
		}
		else if ((order == "go up" || order == "up" || order == "u") && (currentRoom.getz() == 0 || currentRoom.getz() == 1))
		{
			//上楼等价于房间号加9
			location += 9;
			currentRoom = myCastle.rooms[location];
		}
		else if ((order == "go down" || order == "down" || order == "d") && (currentRoom.getz() == 2 || currentRoom.getz() == 1))
		{
			//下楼等价于房间号减9
			location -= 9;
			currentRoom = myCastle.rooms[location];
		}
		else
		{
			//看不懂你的指令
			cout << "Invalid order!" << endl;
			// goto语句防止这种情况发生：你在起点输入了错误指令，而程序却判断成你是从宫殿内回到起点的
			goto loop;
		}
		started = 1;
	}
	//退出循环可能是因为遇见怪物或者救出公主，这里进行判断
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
	//例如：no=16,则x=1,y=2,z=1,本质上是3进制
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
	//根据房间坐标判断出口情况
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
	//房间号与坐标本质上是十进制与三进制的关系
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
	//随机指定怪物和公主生成的房间
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