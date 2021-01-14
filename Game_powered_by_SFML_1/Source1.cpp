//#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
//#include <iostream>
//#include <conio.h>
//#include "map.h"
//#include <Windows.h>
//#include <cstdlib>
//#include <cmath>
//#include <vector>
//#include <list>
//using namespace sf;
//using namespace std;
//
//class MapsCorner
//{
//	Image corner_image; // створили об'єкт Image
//	Texture corner_texture; // створили об'єкт Texture
//	Sprite corner_sprite; // створили об'єкт Sprite
//
//	float x, y, width, height;
//	string texture_file;
//public:
//	MapsCorner(string file)
//	{
//		texture_file = file;
//
//		corner_image.loadFromFile("images\\" + texture_file);
//		corner_texture.loadFromImage(corner_image);
//		corner_sprite.setTexture(corner_texture);
//	}
//
//	void TypeOfSprite(int a)
//	{
//		switch (a)
//		{
//		case 0:
//		{
//			corner_sprite.setTextureRect(IntRect(0, 96, 128, 128));
//			corner_sprite.setPosition(0, 0);
//			break;
//		}
//		case 1:
//		{
//			corner_sprite.setTextureRect(IntRect(128, 96, 128, 128));
//			corner_sprite.setPosition(896, 0);
//			break;
//		}
//		case 2:
//		{
//			corner_sprite.setTextureRect(IntRect(0, 224, 128, 128));
//			corner_sprite.setPosition(0, 576);
//			break;
//		}
//		case 3:
//		{
//			corner_sprite.setTextureRect(IntRect(128, 224, 128, 128));
//			corner_sprite.setPosition(896, 576);
//			break;
//		}
//		}
//	}
//
//	Sprite ReturnSprite()
//	{
//		return corner_sprite;
//	}
//};
//
//class Player
//{
//private:
//	float x, y, dx, dy, size_x, size_y, width, height, acc_x, acc_y, speed, time_hero; // x y - координати, weight hight - ширина та висота спрайта, acc_x acc_y прискорення по відповідним координатам, speed - швидкість
//	int dir; // задає напрям головного героя
//	string texture_file;
//	Image hero_image; // створили об'єкт Image
//	Texture hero_texture; // створили об'єкт Texture
//
//	int i = 0, j = 0;
//	float CurrentFrame = 0;
//	int Frame = 0;
//
//	int size_of_life = 10;
//	bool Life = 1;
//
//
//public:
//	Sprite hero_sprite; // створили об'єкт Sprite
//	//конструктор
//	Player(string file, int Size_X, int Size_Y, int X, int Y, int W, int H)
//	{
//		texture_file = file;
//		size_x = Size_X; size_y = Size_Y;
//		x = X; y = Y;
//		dx = 0;
//		dy = 0;
//		width = W; height = H;
//		time_hero = 1; // змінна є коефіціентом для швидкості, тобто слугуватиме для прискорення та уповільнення героя
//		speed = 1;
//		hero_image.loadFromFile("images\\" + texture_file);      // завантажили в об'єкт hero_image картинку
//		hero_texture.loadFromImage(hero_image);               // завантажили в об'єкт hero_texture об'єкт hero_image
//		hero_sprite.setTexture(hero_texture);                 // завантажили в об'єкт hero_sprite об'єкт hero_texture
//		hero_sprite.setTextureRect(IntRect(2, 2, width, height));
//		hero_sprite.setScale(size_x, size_y);
//		hero_sprite.setPosition(x, y);
//
//	}
//
//	//-----Основні методи-----
//
//	FloatRect getRect()
//	{
//		return FloatRect(x, y, width, height);
//	}
//
//	void Direction(float time)
//	{
//		// LEFT
//		if (Keyboard::isKeyPressed(Keyboard::Left))
//		{
//			setDirection(6);
//			setSpeed(0.27);
//		}
//		// UP
//		if (Keyboard::isKeyPressed(Keyboard::Up))
//		{
//			setDirection(0);
//			setSpeed(0.27);
//		}
//		// RIGHT
//		if (Keyboard::isKeyPressed(Keyboard::Right))
//		{
//			setDirection(2);
//			setSpeed(0.27);
//		}
//		// DOWN
//		if (Keyboard::isKeyPressed(Keyboard::Down))
//		{
//			setDirection(4);
//			setSpeed(0.27);
//		}
//		// LEFT+UP
//		if (Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Up))
//		{
//			setDirection(7);
//			setSpeed(0.23);
//		}
//		// UP+RIGHT
//		if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right))
//		{
//			setDirection(1);
//			setSpeed(0.23);
//		}
//		//RIGHT+DOWN
//		if (Keyboard::isKeyPressed(Keyboard::Right) && Keyboard::isKeyPressed(Keyboard::Down))
//		{
//			setDirection(3);
//			setSpeed(0.23);
//
//		}
//		// LEFT+DOWN
//		if (Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Down)) // LEFT+DOWN
//		{
//			setDirection(5);
//			setSpeed(0.23);
//		}
//
//	}
//
//	void StandartMove(float time)
//	{
//		Direction(time);
//
//		switch (dir)
//		{
//		case 6:
//		{
//			dx = (-speed)*time_hero;
//			dy = 0;
//			break;
//		}
//		case 0:
//		{
//			dx = 0;
//			dy = (-speed)*time_hero;
//			break;
//		}
//		case 2:
//		{
//			dx = speed * time_hero;
//			dy = 0;
//			break;
//		}
//		case 4:
//		{
//			dx = 0;
//			dy = speed * time_hero;
//			break;
//		}
//		case 7:
//		{
//			dx = -speed * time_hero;
//			dy = -speed * time_hero;
//			break;
//		}
//		case 1:
//		{
//			dx = speed * time_hero;
//			dy = -speed * time_hero;
//			break;
//		}
//		case 3:
//		{
//			dx = speed * time_hero;
//			dy = speed * time_hero;
//			break;
//		}
//		case 5:
//		{
//			dx = -speed * time_hero;
//			dy = speed * time_hero;
//			break;
//		}
//		}
//
//		x += dx * time;
//		y += dy * time;
//
//		if ((x < 30.0 || x > 922.0) || (y < 30.0 || y > 602.0))
//		{
//			x -= dx * time;
//			y -= dy * time;
//		}
//
//		speed = 0;
//		hero_sprite.setPosition(x, y);
//	}
//
//	void SetDamage(float time) // При тарані
//	{
//		size_of_life -= 1;
//		if (size_of_life == 0)
//		{
//			Life = false;
//		}
//	}
//
//	void CheckKill(float time)
//	{
//		if (Life == false)
//		{
//			/*StandartAnimation(time, 1);*/
//			/*object_sprite.setPosition(-300, -300);
//			set_x(64 * (1 + rand() % 14));
//			set_y(-150);*/
//			/*set_Life(true);
//			set_q_of_life(1);
//			set_atack(true);
//			set_pause(2000);*/
//			hero_sprite.setScale(1.5, 1.5);
//		}
//
//
//	}
//
//	void StandartAnimation(float time, int a)
//	{
//
//		if (a == 0)
//		{
//			// LEFT
//			if (dir == 6)
//			{
//				CurrentFrame += 0.01*time;
//				if (CurrentFrame > 3) { CurrentFrame = 0; }
//				hero_sprite.setTextureRect(IntRect(SelectSprite_X(6, int(CurrentFrame)), SelectSprite_Y(6), 72, 72));
//				hero_sprite.setScale(size_x, size_y);
//			}
//			// UP
//			if (dir == 0)
//			{
//				CurrentFrame += 0.01*time;
//				if (CurrentFrame > 3) { CurrentFrame = 0; }
//				hero_sprite.setTextureRect(IntRect(SelectSprite_X(0, int(CurrentFrame)), SelectSprite_Y(0), 72, 72));
//				hero_sprite.setScale(size_x, size_y);
//
//			}
//			// RIGHT
//			if (dir == 2)
//			{
//				CurrentFrame += 0.01*time;
//				if (CurrentFrame > 3) { CurrentFrame = 0; }
//				hero_sprite.setTextureRect(IntRect(SelectSprite_X(2, int(CurrentFrame)), SelectSprite_Y(2), 72, 72));
//				hero_sprite.setScale(size_x, size_y);
//			}
//			// DOWN
//			if (dir == 4)
//			{
//				CurrentFrame += 0.01*time;
//				if (CurrentFrame > 3) { CurrentFrame = 0; }
//				hero_sprite.setTextureRect(IntRect(SelectSprite_X(4, int(CurrentFrame)), SelectSprite_Y(4), 72, 72));
//				hero_sprite.setScale(size_x, size_y);
//
//			}
//			// LEFT+UP
//			if (dir == 7)
//			{
//				CurrentFrame += 0.01*time;
//				if (CurrentFrame > 3) { CurrentFrame = 0; }
//				hero_sprite.setTextureRect(IntRect(SelectSprite_X(7, int(CurrentFrame)), SelectSprite_Y(7), 72, 72));
//				hero_sprite.setScale(size_x, size_y);
//			}
//			// UP+RIGHT
//			if (dir == 1)
//			{
//				CurrentFrame += 0.01*time;
//				if (CurrentFrame > 3) { CurrentFrame = 0; }
//				hero_sprite.setTextureRect(IntRect(SelectSprite_X(1, int(CurrentFrame)), SelectSprite_Y(1), 72, 72));
//				hero_sprite.setScale(size_x, size_y);
//			}
//			//RIGHT+DOWN
//			if (dir == 3)
//			{
//				CurrentFrame += 0.01*time;
//				if (CurrentFrame > 3) { CurrentFrame = 0; }
//				hero_sprite.setTextureRect(IntRect(SelectSprite_X(3, int(CurrentFrame)), SelectSprite_Y(3), 72, 72));
//				hero_sprite.setScale(size_x, size_y);
//
//			}
//			// LEFT+DOWN
//			if (dir == 5)
//			{
//				CurrentFrame += 0.01*time;
//				if (CurrentFrame > 3) { CurrentFrame = 0; }
//				hero_sprite.setTextureRect(IntRect(SelectSprite_X(5, int(CurrentFrame)), SelectSprite_Y(5), 72, 72));
//				hero_sprite.setScale(size_x, size_y);
//			}
//		}
//		else
//		{
//			if (get_Frame() > 0 && get_Frame() <= 100)
//			{
//				hero_sprite.setTextureRect(IntRect(0, 384, 72, 72));
//			}
//			if (get_Frame() > 100 && get_Frame() <= 200)
//			{
//				hero_sprite.setTextureRect(IntRect(73, 384, 72, 72));
//			}
//			if (get_Frame() > 200 && get_Frame() <= 300)
//			{
//				hero_sprite.setTextureRect(IntRect(145, 384, 72, 72));
//			}
//			if (get_Frame() > 300 && get_Frame() <= 400)
//			{
//				hero_sprite.setTextureRect(IntRect(217, 384, 72, 72));
//			}
//			if (get_Frame() > 400 && get_Frame() <= 600)
//			{
//				hero_sprite.setTextureRect(IntRect(289, 384, 72, 72));
//				/*x = -350;
//				y = -350;*/
//
//			}
//		}
//
//	}
//	//------------------------\\
//
//	//-----Допоміжні методи-----
//
//	void set_Life(bool a)
//	{
//		Life = a;
//	}
//	int get_dir()
//	{
//		return dir;
//	}
//	void set_dx(float a)
//	{
//		dx = a;
//	}
//	void set_dy(float a)
//	{
//		dy = a;
//	}
//	int get_dx()
//	{
//		return dx;
//	}
//	int get_dy()
//	{
//		return dy;
//	}
//	int get_size_life()
//	{
//		return size_of_life;
//	}
//	void set_x(int a)
//	{
//		x = a;
//	}
//	void set_y(int a)
//	{
//		y = a;
//	}
//	int get_x()
//	{
//		return x;
//	}
//	int get_y()
//	{
//		return y;
//	}
//	bool get_Life()
//	{
//		return Life;
//	}
//	void add_Frame(float a)
//	{
//		Frame += a;
//	}
//	void add_x(float a)
//	{
//		x += a;
//	}
//	void add_y(float a)
//	{
//		y += a;
//	}
//	int get_Frame()
//	{
//		return Frame;
//	}
//	void set_Frame(int a)
//	{
//		Frame = a;
//	}
//	int SelectSprite_X(int dir, int a)
//	{
//		if (dir % 2 == 0)
//		{
//			switch (a)
//			{
//			case 0:
//			{
//				return 2;
//			}
//			case 1:
//			{
//				return 79;
//			}
//			case 2:
//			{
//				return 156;
//			}
//			}
//		}
//		else
//		{
//			switch (a)
//			{
//			case 0:
//			{
//				return 233;
//			}
//			case 1:
//			{
//				return 310;
//			}
//			case 2:
//			{
//				return 387;
//			}
//			}
//		}
//
//	}
//	int SelectSprite_Y(int dir)
//	{
//		if (dir == 0 || dir == 1)
//		{
//			return 2;
//		}
//		if (dir == 2 || dir == 3)
//		{
//			return 79;
//		}
//		if (dir == 4 || dir == 5)
//		{
//			return 156;
//		}
//		if (dir == 6 || dir == 7)
//		{
//			return 233;
//		}
//	}
//	void setSpeed(float speed1) { speed = speed1; }
//	void setDirection(int dir1) { dir = dir1; }
//	Sprite ReturnSprite()
//	{
//		return hero_sprite;
//	}
//	//--------------------------\\
//
//};
//
//class Bullet : public Player
//{
//	int direction;
//
//public:
//	Bullet(string file, int Size_X, int Size_Y, int X, int Y, int W, int H, int Direction) : Player(file, Size_X, Size_Y, X, Y, W, H)
//	{
//		direction = Direction;
//	}
//
//	void BulletMove(float time)
//	{
//		hero_sprite.setTextureRect(IntRect(0, 0, 16, 16));
//		switch (direction)
//		{
//		case 6:
//		{
//			add_x((-0.7)*time);
//			add_y(0);
//			break;
//		}
//		case 0:
//		{
//			add_x(0);
//			add_y((-0.7)*time);
//			break;
//		}
//		case 2:
//		{
//			add_x(0.7 * time);
//			add_y(0);
//			break;
//		}
//		case 4:
//		{
//			add_x(0);
//			add_y(0.7 * time);
//			break;
//		}
//		case 7:
//		{
//			add_x(-0.45 * time);
//			add_y(-0.45 * time);
//			break;
//		}
//		case 1:
//		{
//			add_x(0.45 * time);
//			add_y(-0.45 * time);
//			break;
//		}
//		case 3:
//		{
//			add_x(0.45 * time);
//			add_y(0.45 * time);
//			break;
//		}
//		case 5:
//		{
//			add_x(-0.45 * time);
//			add_y(0.45 * time);
//			break;
//		}
//		}
//
//		/*add_x(get_dx() * time);
//		add_y(get_dy() * time);*/
//
//		/*if ((x < 30.0 || x > 922.0) || (y < 30.0 || y > 602.0))
//		{
//			x -= dx * time;
//			y -= dy * time;
//		}*/
//
//		/*speed = 0;*/
//		hero_sprite.setPosition(get_x(), get_y());
//	}
//
//	void bull()
//	{
//		direction = 0; set_x(-500); set_y(500);
//		hero_sprite.setPosition(get_x(), get_y());
//	}
//};
//
//class Cloud
//{
//	Image image_cloud;
//	Texture texture_cloud;
//
//	string texture_file;
//	float x, y, width, height, speed, timer;
//	float CurrentTime = 0;
//	int type, flag = 0, flag_1 = 0;
//public:
//	Sprite sprite_cloud;
//	Cloud(string file)
//	{
//		texture_file = file;
//
//		image_cloud.loadFromFile("images\\" + texture_file);
//		texture_cloud.loadFromImage(image_cloud);
//		sprite_cloud.setTexture(texture_cloud);
//
//		timer = (rand() % 10);
//	}
//
//	int get_x_1()
//	{
//		return x;
//	}
//	int get_y_1()
//	{
//		return y;
//	}
//	int get_w_1()
//	{
//		return width;
//	}
//	int get_h_1()
//	{
//		return height
//			;
//	}
//
//	void set_x_1(int a)
//	{
//		x = a;
//	}
//	void set_y_1(int a)
//	{
//		y = a;
//	}
//	void set_w_1(int a)
//	{
//		width = a;
//	}
//	void set_h_1(int a)
//	{
//		height = a;
//	}
//
//
//	int RandPosition()
//	{
//		x = rand() % 780;
//		y = -350;
//		speed = (double)rand() / (double)RAND_MAX*(0.4 - 0.11) + 0.11;
//		width = (double)rand() / (double)RAND_MAX*(3.1 - 1.0) + 1.0;
//		height = width;
//		type = rand() % 10;
//		switch (type)
//		{
//		case 0:
//		{
//			sprite_cloud.setTextureRect(IntRect(0, 0, 128, 80));
//			break;
//		}
//		case 1:
//		{
//			sprite_cloud.setTextureRect(IntRect(129, 0, 128, 80));
//			break;
//		}
//		case 2:
//		{
//			sprite_cloud.setTextureRect(IntRect(0, 80, 128, 80));
//			break;
//		}
//		case 3:
//		{
//			sprite_cloud.setTextureRect(IntRect(129, 80, 128, 80));
//			break;
//		}
//		case 4:
//		{
//			sprite_cloud.setTextureRect(IntRect(0, 160, 128, 80));
//			break;
//		}
//		case 5:
//		{
//			sprite_cloud.setTextureRect(IntRect(129, 160, 128, 80));
//			break;
//		}
//		case 6:
//		{
//			sprite_cloud.setTextureRect(IntRect(0, 240, 128, 80));
//			break;
//		}
//		case 7:
//		{
//			sprite_cloud.setTextureRect(IntRect(129, 240, 128, 80));
//			break;
//		}
//		case 8:
//		{
//			sprite_cloud.setTextureRect(IntRect(0, 320, 128, 80));
//			break;
//		}
//		case 9:
//		{
//			sprite_cloud.setTextureRect(IntRect(129, 320, 128, 80));
//			break;
//		}
//		case 10:
//		{
//			sprite_cloud.setTextureRect(IntRect(0, 400, 128, 80));
//			break;
//		}
//		}
//
//
//		return 1;
//	}
//
//	float RandTimer()
//	{
//		return rand() % 5;
//	}
//
//	void SpawnAndMove(float time)
//	{
//		if (flag == 0)
//		{
//			flag = RandPosition();
//		}
//
//		if (timer < 0)
//		{
//			timer = RandTimer();
//			CurrentTime += speed * time*0.001;
//			if (y > 800) { flag = 0; CurrentTime = 0; }
//			y += CurrentTime;
//			sprite_cloud.setScale(width, height);
//			sprite_cloud.setPosition(x, y);
//		}
//		timer -= time;
//
//	}
//
//	Sprite ReturnSprite()
//	{
//		return sprite_cloud;
//	}
//};
//
//class SpidometerData : public Cloud
//{
//	int choise;
//	Image image_arrow;
//	Texture texture_arrow;
//
//
//	string texture_file_arrow;
//	float x_2, y_2, width_2, height_2;
//public:
//	Sprite sprite_arrow;
//	SpidometerData(string file_1, string file_2, int X_1, int Y_1, int W_1, int H_1, int X_2, int Y_2, int W_2, int H_2) : Cloud(file_1)
//	{
//		texture_file_arrow = file_2;
//
//		image_arrow.loadFromFile("images\\" + texture_file_arrow);
//		texture_arrow.loadFromImage(image_arrow);
//		sprite_arrow.setTexture(texture_arrow);
//
//		set_x_1(X_1);
//		set_y_1(Y_1);
//		set_w_1(W_1);
//		set_h_1(H_1);
//		x_2 = X_2;
//		y_2 = Y_2;
//		width_2 = W_2;
//		height_2 = H_2;
//	}
//
//	int get_x_2()
//	{
//		return x_2;
//	}
//	int get_y_2()
//	{
//		return y_2;
//	}
//	int get_w_2()
//	{
//		return width_2;
//	}
//	int get_h_2()
//	{
//		return height_2;
//	}
//	int get_choise()
//	{
//		return choise;
//	}
//
//	void set_x_2(int a)
//	{
//		x_2 = a;
//	}
//	void set_y_2(int a)
//	{
//		y_2 = a;
//	}
//	void set_w_2(int a)
//	{
//		width_2 = a;
//	}
//	void set_h_2(int a)
//	{
//		height_2 = a;
//	}
//	void set_choise(int a)
//	{
//		choise = a;
//	}
//
//	Sprite ReturnSprite_2()
//	{
//		return sprite_arrow;
//	}
//};
//
//class Spidometer : public SpidometerData
//{
//public:
//	Spidometer(string file_1, string file_2, int X_1, int Y_1, int W_1, int H_1, int X_2, int Y_2, int W_2, int H_2) : SpidometerData(file_1, file_2, X_1, Y_1, W_1, H_1, X_2, Y_2, W_2, H_2)
//	{
//
//	}
//
//	void SetText_1()
//	{
//		sprite_cloud.setTextureRect(IntRect(get_x_1(), get_y_1(), get_w_1(), get_h_1()));
//	}
//
//	void SetText_2(int Size_of_Life)
//	{
//		switch (Size_of_Life)
//		{
//		case 10:
//		{
//			sprite_arrow.setTextureRect(IntRect(193, 128, get_w_2(), get_h_2()));
//			break;
//		}
//		case 9:
//		{
//			sprite_arrow.setTextureRect(IntRect(193, 240, get_w_2(), get_h_2()));
//			break;
//		}
//		case 8:
//		{
//			sprite_arrow.setTextureRect(IntRect(193, 352, get_w_2(), get_h_2()));
//			break;
//		}
//		case 7:
//		{
//			sprite_arrow.setTextureRect(IntRect(193, 464, get_w_2(), get_h_2()));
//			break;
//		}
//		case 6:
//		{
//			sprite_arrow.setTextureRect(IntRect(193, 576, get_w_2(), get_h_2()));
//			break;
//		}
//		case 5:
//		{
//			sprite_arrow.setTextureRect(IntRect(0, 688, get_w_2(), get_h_2()));
//			break;
//		}
//		case 4:
//		{
//			sprite_arrow.setTextureRect(IntRect(0, 576, get_w_2(), get_h_2()));
//			break;
//		}
//		case 3:
//		{
//			sprite_arrow.setTextureRect(IntRect(0, 464, get_w_2(), get_h_2()));
//			break;
//		}
//		case 2:
//		{
//			sprite_arrow.setTextureRect(IntRect(0, 352, get_w_2(), get_h_2()));
//			break;
//		}
//		case 1:
//		{
//			sprite_arrow.setTextureRect(IntRect(0, 240, get_w_2(), get_h_2()));
//			break;
//		}
//		case 0:
//		{
//			sprite_arrow.setTextureRect(IntRect(0, 128, get_w_2(), get_h_2()));
//			break;
//		}
//		}
//	}
//
//	void Set_Pos_1(int a, int b)
//	{
//		sprite_cloud.setPosition(a, b);
//	}
//
//	void Set_Pos_2(int a, int b)
//	{
//		sprite_arrow.setPosition(a, b);
//	}
//
//};
//
//class PanelList : public Cloud
//{
//	Image image_panel_list;
//	Texture texture_panel_list;
//
//	Image image_light;
//	Texture texture_light;
//
//
//	string texture_file_panel_list;
//	float x_2, y_2, width_2, height_2;
//
//	int CurrentFrame = 0;
//	int CurrentFrame_1 = 0;
//public:
//	Sprite sprite_panel_list;
//	Sprite sprite_light;
//	PanelList(string file_1, string file_2, int X_1, int Y_1, int X_2, int Y_2) : Cloud(file_1)
//	{
//		texture_file_panel_list = file_2;
//
//		image_panel_list.loadFromFile("images\\" + texture_file_panel_list);
//		texture_panel_list.loadFromImage(image_panel_list);
//		sprite_panel_list.setTexture(texture_panel_list);
//
//		image_light.loadFromFile("images\\" + texture_file_panel_list);
//		texture_light.loadFromImage(image_light);
//		sprite_light.setTexture(texture_light);
//
//		set_x_1(X_1);
//		set_y_1(Y_1);
//		x_2 = X_2;
//		y_2 = Y_2;
//		sprite_cloud.setTextureRect(IntRect(0, 0, 128, 192));
//		sprite_cloud.setTextureRect(IntRect(400, 0, 106, 144));
//	}
//
//	void SetText_1(float time)
//	{
//		CurrentFrame += time;
//		if (CurrentFrame > 750) { CurrentFrame = 0; }
//		if (CurrentFrame > 0 && CurrentFrame <= 250)
//		{
//			sprite_cloud.setTextureRect(IntRect(0, 0, 128, 192));
//		}
//		if (CurrentFrame > 250 && CurrentFrame <= 500)
//		{
//			sprite_cloud.setTextureRect(IntRect(128, 0, 128, 192));
//		}
//		if (CurrentFrame > 500 && CurrentFrame <= 750)
//		{
//			sprite_cloud.setTextureRect(IntRect(256, 0, 128, 192));
//		}
//	}
//
//	void SetText_2(float time)
//	{
//		y_2 += 0.01*time;
//		if (CurrentFrame == 1288) { x_2 = 400; y_2 = 0; }
//		sprite_panel_list.setTextureRect(IntRect(x_2, y_2, 106, 144));
//	}
//
//	void Set_Pos_1(int a, int b)
//	{
//		sprite_cloud.setPosition(a, b);
//	}
//
//	void Set_Pos_2(int a, int b)
//	{
//		sprite_panel_list.setPosition(a, b);
//	}
//
//	void Light(int x, float time)
//	{
//		sprite_light.setPosition(1040, 408);
//		if (x < 4)
//		{
//			CurrentFrame_1 += 0.1*time;
//			if (CurrentFrame_1 > 200) { CurrentFrame_1 = 0; }
//			if (CurrentFrame > 0 && CurrentFrame <= 130)
//			{
//				sprite_light.setTextureRect(IntRect(0, 336, 192, 112));
//			}
//			if (CurrentFrame > 130 && CurrentFrame <= 200)
//			{
//				sprite_light.setTextureRect(IntRect(0, 448, 192, 112));
//			}
//		}
//		else
//		{
//			sprite_light.setTextureRect(IntRect(0, 224, 192, 112));
//		}
//	}
//
//	int get_x_2()
//	{
//		return x_2;
//	}
//	int get_y_2()
//	{
//		return y_2;
//	}
//	int get_w_2()
//	{
//		return width_2;
//	}
//	int get_h_2()
//	{
//		return height_2;
//	}
//
//	void set_x_2(int a)
//	{
//		x_2 = a;
//	}
//	void set_y_2(int a)
//	{
//		y_2 = a;
//	}
//	void set_w_2(int a)
//	{
//		width_2 = a;
//	}
//	void set_h_2(int a)
//	{
//		height_2 = a;
//	}
//
//	Sprite ReturnSprite_2()
//	{
//		return sprite_panel_list;
//	}
//	Sprite ReturnSprite_3()
//	{
//		return sprite_light;
//	}
//};
//
//class Map
//{
//	Image image_map;
//	Texture texture_map;
//	Sprite sprite_map;
//	string texture_file;
//	int i = 0, j = 0;
//	int x, y, h, w;
//
//	int temp = 2816;
//	float CurrentTime = 0;
//	// Для обмеження гравця
//	Image map_break_image;
//	Texture map_break_texture;
//	// --------------------
//
//public:
//
//	Sprite map_break_sprite;
//
//	Map(string file, int X, int Y, int W, int H)
//	{
//		texture_file = file;
//		x = X; //0 координати для вікна
//		y = Y; //0
//		h = H; // координати розміру мапи
//		w = W; //
//		image_map.loadFromFile(file);
//		texture_map.loadFromImage(image_map);
//		sprite_map.setTexture(texture_map);
//
//		sprite_map.setTextureRect(IntRect(0, 2816, w, h));
//		sprite_map.setPosition(x, y);
//
//		// Для рамки
//		map_break_image.loadFromFile("images\\break.png");
//		map_break_texture.loadFromImage(map_break_image);
//		map_break_sprite.setTexture(map_break_texture);
//	}
//
//	void MapMove(float time)
//	{
//		CurrentTime += 0.005*time;
//		if (CurrentTime > 0.1)
//		{
//			CurrentTime = 0;
//			sprite_map.setTextureRect(IntRect(0, temp, w, h));
//			temp--;
//		}
//		if (temp == 0)
//		{
//			temp = 2816;
//			sprite_map.setTextureRect(IntRect(0, temp, w, h));
//		}
//	}
//
//	Sprite ReturnSprite()
//	{
//		return sprite_map;
//	}
//
//	// Для рамки
//	void map_break_sprite_setTextureRect_break()
//	{
//		map_break_sprite.setTextureRect(IntRect(0, 32, 32, 32));
//	}
//	void map_break_sprite_setTextureRect_space()
//	{
//		map_break_sprite.setTextureRect(IntRect(32, 0, 32, 32));
//	}
//	void map_break_sprite_setTextureRect_1()
//	{
//		map_break_sprite.setTextureRect(IntRect(176, 0, 32, 32));
//	}
//	void map_break_sprite_setTextureRect_2()
//	{
//		map_break_sprite.setTextureRect(IntRect(208, 0, 32, 32));
//	}
//	void map_break_sprite_setTextureRect_3()
//	{
//		map_break_sprite.setTextureRect(IntRect(240, 0, 32, 32));
//	}
//	void map_break_sprite_setTextureRect_4()
//	{
//		map_break_sprite.setTextureRect(IntRect(240, 32, 32, 32));
//	}
//	void map_break_sprite_setTextureRect_5()
//	{
//		map_break_sprite.setTextureRect(IntRect(240, 64, 32, 32));
//	}
//	void map_break_sprite_setTextureRect_6()
//	{
//		map_break_sprite.setTextureRect(IntRect(208, 64, 32, 32));
//	}
//	void map_break_sprite_setTextureRect_7()
//	{
//		map_break_sprite.setTextureRect(IntRect(176, 64, 32, 32));
//	}
//	void map_break_sprite_setTextureRect_8()
//	{
//		map_break_sprite.setTextureRect(IntRect(176, 32, 32, 32));
//	}
//	void map_break_sprite_setTextureRect_9()
//	{
//		map_break_sprite.setTextureRect(IntRect(0, 64, 32, 32));
//	}
//
//	void map_break_sprite_setPosition()
//	{
//		map_break_sprite.setPosition(j * 32, i * 32);
//	}
//	Sprite Return_map_break_sprite()
//	{
//		return map_break_sprite;
//	}
//};
//
//class BaseOfSubject
//{
//	float x, y, dx, dy, size_x, size_y, speed;// x y - координати, weight hight - ширина та висота спрайта, speed - швидкість, dx dy - координати для руху
//	float time_object;// змінна є коефіціентом для швидкості, тобто слугуватиме для прискорення та уповільнення героя
//	int width, height;
//	int dir; // задає напрям об'єкта
//	int size_of_life; // кількість здоров'я
//	float pause; // зміна, що встановлює час "замирання" об'єкта після смерті до моменту нової появи.
//
//	string object_name;
//
//	bool atack; // показує, чи об'єкт наносить собою урон, чи ні
//	bool Life; // показує, чи живий об'єкт, чи ні
//	bool respawn; // Встановіть true , щоб об'єкт мав змогу відродитись
//
//	int i = 0, j = 0;
//	float CurrentFrame = 0;
//
//	int point = 0;
//
//	int Frame = 0;
//
//public:
//
//	void add_Frame(float a)
//	{
//		Frame += a;
//	}
//	int get_Frame()
//	{
//		return Frame;
//	}
//	void set_Frame(int a)
//	{
//		Frame = a;
//	}
//
//	Texture object_texture;
//	Sprite object_sprite;
//
//	//Конструктор
//	BaseOfSubject(Image &object_image, float X, float Y, int W, int H, float Speed, int SizeLife, float Time, int Dir, bool Atack, float Pause, bool Respawn, string Name)
//	{
//		object_texture.loadFromImage(object_image);
//		object_sprite.setTexture(object_texture);
//
//		dir = Dir;
//		x = X;
//		y = Y;
//		width = W;
//		height = H;
//		size_x = size_y = 1;
//		speed = Speed;
//		size_of_life = SizeLife;
//		object_name = Name;
//		Life = 1;
//		pause = Pause;
//		atack = Atack;
//		respawn = Respawn;
//		dx = 0;
//		dy = 0;
//		time_object = Time;
//	}
//
//
//	void set_x(float a)
//	{
//		x = a;
//	}
//	void set_y(float a)
//	{
//		y = a;
//	}
//	void set_w(int a)
//	{
//		width = a;
//	}
//	void set_h(int a)
//	{
//		height = a;
//	}
//	void set_dx(float a)
//	{
//		dx = a;
//	}
//	void set_dy(float a)
//	{
//		dy = a;
//	}
//	void set_dir(int a)
//	{
//		dir = a;
//	}
//	void set_speed(float a)
//	{
//		speed = a;
//	}
//
//	void set_q_of_life(int a)
//	{
//		size_of_life = a;
//	}
//
//	void set_Life(bool a)
//	{
//		Life = a;
//	}
//	void set_size_x(float a)
//	{
//		size_x = a;
//	}
//	void set_size_y(float a)
//	{
//		size_y = a;
//	}
//	void set_time_object(float a)
//	{
//		time_object = a;
//	}
//	void set_pause(float a)
//	{
//		pause = a;
//	}
//	void set_respawn(bool a)
//	{
//		respawn = a;
//	}
//	void set_atack(bool a)
//	{
//		atack = a;
//	}
//
//	//-----------------------//
//
//	float get_x()
//	{
//		return x;
//	}
//	float get_y()
//	{
//		return y;
//	}
//	int get_w()
//	{
//		return width;
//	}
//	int get_h()
//	{
//		return height;
//	}
//	float get_dx()
//	{
//		return dx;
//	}
//	float get_dy()
//	{
//		return dy;
//	}
//	int get_dir()
//	{
//		return dir;
//	}
//	float get_speed()
//	{
//		return speed;
//	}
//	int get_size_of_life()
//	{
//		return size_of_life;
//	}
//	bool get_Life()
//	{
//		return Life;
//	}
//	int get_size_x()
//	{
//		return size_x;
//	}
//	int get_size_y()
//	{
//		return size_y;
//	}
//	float get_time_object()
//	{
//		return time_object;
//	}
//	float get_pause()
//	{
//		return pause;
//	}
//	bool get_respawn()
//	{
//		return respawn;
//	}
//	bool get_atack()
//	{
//		return atack;
//	}
//	string get_name()
//	{
//		return object_name;
//	}
//
//	//-----------------------//
//
//	void add_x(float a)
//	{
//		x += a;
//	}
//	void add_y(float a)
//	{
//		y += a;
//	}
//	void add_pause(float a)
//	{
//		pause += a;
//	}
//	void decrement_life(int a)
//	{
//		size_of_life -= a;
//		if (get_size_of_life() <= 0)
//		{
//			set_Life(false);
//		}
//	}
//	void decrement_pause(float time)
//	{
//		pause -= time;
//	}
//
//	FloatRect getRect()
//	{
//		return FloatRect(x, y, width, height);
//	}
//
//	virtual void StandartMove(float time) = 0;
//	virtual void StandartAnimation(float time, int a) = 0;
//	virtual void CheckKill(float time) = 0;
//	virtual void SetDamage(float time) = 0;
//
//	Sprite ReturnSprite()
//	{
//		return object_sprite;
//	}
//};
//
//class Enemy : public BaseOfSubject
//{
//	int type_of_enemi;
//	int flag = 0;
//
//	float timer = 0;
//	float sec = 0;
//
//public:
//	Enemy(int TypeOfEnemi, Image &object_image, float X, float Y, int W, int H, float Speed, int SizeLife, float Time, int Dir, int Atack, float Pause, bool Respawn, string Name) : BaseOfSubject(object_image, X, Y, W, H, Speed, SizeLife, Time, Dir, Atack, Pause, Respawn, Name)
//	{
//		type_of_enemi = TypeOfEnemi;
//
//		switch (type_of_enemi)
//		{
//		case 1:
//		{
//			object_sprite.setTextureRect(IntRect(0, 0, W, H));
//			object_sprite.setPosition(get_x(), get_y());
//			set_dir(4);
//			break;
//		}
//		case 2:
//		{
//
//			break;
//		}
//		case 3:
//		{
//
//			break;
//		}
//		}
//	}
//
//	int SpawnPlace()
//	{
//		return 64 * (1 + rand() % 14);
//	}
//
//	void StandartMove(float time)
//	{
//
//		switch (type_of_enemi)
//		{
//		case 1:
//		{
//			switch (get_dir())
//			{
//			case 4:
//			{
//				if (timer < 0 && flag == 0)
//				{
//					flag = 1;
//					set_x(SpawnPlace());
//					set_y(-150);
//				}
//
//				if (flag == 1)
//				{
//					if (get_y() > 800) { timer = 100 + rand() % 5000; flag = 0; }
//				}
//				timer -= time;
//
//				set_dx(0);
//				set_dy((get_speed())*(get_time_object()));
//
//				add_x(get_dx() * time);
//				add_y(get_dy() * time);
//
//				object_sprite.setPosition(get_x(), get_y());
//
//				break;
//			}
//			}
//		}
//		case 2:
//		{
//
//			break;
//		}
//		case 3:
//		{
//
//			break;
//		}
//		}
//	}
//
//	void SetDamage(float time) // При тарані
//	{
//		decrement_life(1);
//		set_atack(false);
//	}
//
//	void CheckKill(float time)
//	{
//		if (get_Life() == false)
//		{
//			/*StandartAnimation(time, 1);*/
//			/*object_sprite.setPosition(-300, -300);
//			set_x(64 * (1 + rand() % 14));
//			set_y(-150);*/
//			set_Life(true);
//			set_q_of_life(1);
//			set_atack(true);
//			set_pause(2000);
//		}
//
//
//	}
//
//	void StandartAnimation(float time, int a) // якщо а == 0, то беремо стандартну анімацію, якщо а == 1, то беремо анімацію смерті
//	{
//		switch (type_of_enemi)
//		{
//		case 1:
//		{
//			switch (get_dir())
//			{
//			case 4:
//			{
//				if (a == 0)
//				{
//					object_sprite.setTextureRect(IntRect(0, 0, get_w(), get_h()));
//				}
//				else
//				{
//					/*object_sprite.setPosition(get_x(), get_y());
//					CurrentFrame += 0.4*time;
//					object_sprite.setTextureRect(IntRect(64 + 64 * CurrentFrame, 0, 64, 64));
//
//					if (CurrentFrame > 4)
//					{
//						object_sprite.setTextureRect(IntRect(320, 0, 64, 64));
//						object_sprite.setPosition(-300, -300);
//						CurrentFrame = 0;
//					}*/
//					if (get_Frame() > 0 && get_Frame() <= 100)
//					{
//						object_sprite.setTextureRect(IntRect(64, 0, 64, 64));
//					}
//					if (get_Frame() > 100 && get_Frame() <= 200)
//					{
//						object_sprite.setTextureRect(IntRect(128, 0, 64, 64));
//					}
//					if (get_Frame() > 200 && get_Frame() <= 300)
//					{
//						object_sprite.setTextureRect(IntRect(196, 0, 64, 64));
//					}
//					if (get_Frame() > 300 && get_Frame() <= 400)
//					{
//						object_sprite.setTextureRect(IntRect(256, 0, 64, 64));
//					}
//					if (get_Frame() > 400 && get_Frame() <= 500)
//					{
//						object_sprite.setTextureRect(IntRect(320, 0, 64, 64));
//						object_sprite.setPosition(-300, -300);
//						set_x(64 * (1 + rand() % 14));
//						set_y(-150);
//
//					}
//				}
//				break;
//			}
//			}
//			break;
//		}
//		case 2:
//		{
//
//			break;
//		}
//		case 3:
//		{
//
//			break;
//		}
//		}
//	}
//
//};
//
//class ElementsOfMenu
//{
//
//	string texture_file;
//	float x, y, width, height, d_x = 1, d_y = 1, speed;
//	float CurrentTime = 0;
//	int type;
//	Texture element_texture;
//	int dx = 0, dy = 0;
//	int dir;
//
//public:
//	Sprite element_sprite;
//	ElementsOfMenu(int Type, Image &element_image, int W, int H, int s)
//	{
//		element_texture.loadFromImage(element_image);
//		element_sprite.setTexture(element_texture);
//
//		width = W;
//		height = H;
//		speed = s;
//		type = Type;
//
//		switch (type)
//		{
//		case 0:
//		{
//			x = 30 + rand() % 850;
//			y = 30 + rand() % 350;
//			dir = rand() % 1;
//
//			if (dir == 0)
//			{
//				x = 0;
//				y = 0;
//			}
//			else
//			{
//				x = 64;
//				y = 0;
//			}
//			element_sprite.setTextureRect(IntRect(x, y, width, height));
//
//			break;
//		}
//		case 1:
//		{
//
//			x = 30 + rand() % 850;
//			y = 550;
//			dir = rand() % 1;
//			if (dir == 0)
//			{
//				x = 0;
//				y = 64;
//			}
//			else
//			{
//				x = 96;
//				y = 64;
//			}
//			element_sprite.setTextureRect(IntRect(x, y, width, height));
//
//			break;
//		}
//		}
//	}
//
//	void ElementMove(float time)
//	{
//		switch (type)
//		{
//		case 0:
//		{
//			//if ((x < 30.0 || x > 922.0) || (y < 30.0 || y > 602.0))
//			//{
//			//	x -= dx * time;
//			//	y -= dy * time;
//			//}
//
//			if (x < 30.0 || x > 1200.0)
//			{
//				dx *= -1;
//				if (dir == 0)
//				{
//					element_sprite.setTextureRect(IntRect(0, 0, width, height));
//					dir = 1;
//				}
//				else
//				{
//					element_sprite.setTextureRect(IntRect(64, 0, width, height));
//					dir = 0;
//				}
//			}
//			if (y < 0 || y > 650.0)
//			{
//				dy *= -1;
//			}
//
//			x += d_x * speed * time;
//			y += d_y * speed * time;
//			element_sprite.setPosition(x, y);
//			break;
//		}
//		case 1:
//		{
//			//if ((x < 30.0 || x > 922.0) || (y < 30.0 || y > 602.0))
//			//{
//			//	x -= dx * time;
//			//	y -= dy * time;
//			//}
//
//			if (x < 0 || x > 1200.0)
//			{
//				dx *= -1;
//				if (dir == 0)
//				{
//					element_sprite.setTextureRect(IntRect(0, 64, width, height));
//					dir = 1;
//				}
//				else
//				{
//					element_sprite.setTextureRect(IntRect(96, 64, width, height));
//					dir = 0;
//				}
//
//			}
//
//			x += d_x * speed * time;
//			y += sin((d_y * speed * time)*0.5);
//			element_sprite.setPosition(x, y);
//			break;
//		}
//		}
//	}
//
//	Sprite ReturnSprite()
//	{
//		return element_sprite;
//	}
//};
//
////void Menu(RenderWindow & window, float time)
////{
////	/*bool isActive;
////	Image image_menu;
////	Texture texture_menu;
////	Sprite sprte_menu;
////
////	image_menu.loadFromFile("images\\MainTheme.png");
////	texture_menu.loadFromImage(image_menu);
////	sprte_menu.setTexture(texture_menu);
////
////	Image image_chaika;
////	image_chaika.loadFromFile("images\\elements.png");
////
////
////	list <ElementsOfMenu*> elementMenu;
////	list <ElementsOfMenu*>::iterator it;*/
////
////	for (int i = 0; i < 3; i++)
////	{
////		if(i!=2)
////			elementMenu.push_back(new ElementsOfMenu(0, image_chaika, 64, 48, 0.3));
////		else
////			elementMenu.push_back(new ElementsOfMenu(1, image_chaika, 64, 48, 0.3));
////	}
////	
////	sprte_menu.setPosition(0, 0);
////	window.draw((sprte_menu));
////
////	for (it = elementMenu.begin(); it != elementMenu.end(); it++)
////	{
////		(*it)->ElementMove(time);
////		window.draw((*it)->ReturnSprite());
////	}
////
////}
//
//int main()
//{
//	int AAA = 0;
//	//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
//	/*bool isActive;
//	Image image_menu;
//	Texture texture_menu;
//	Sprite sprte_menu;
//
//	image_menu.loadFromFile("images\\MainTheme.png");
//	texture_menu.loadFromImage(image_menu);
//	sprte_menu.setTexture(texture_menu);
//
//	Image image_chaika;
//	image_chaika.loadFromFile("images\\elements.png");
//
//
//	list <ElementsOfMenu*> elementMenu;
//	list <ElementsOfMenu*>::iterator it;*/
//	//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
//	int timer = 0;
//	int timer_1 = 0;
//
//	srand(time(NULL));
//	int flag = 0;
//	int i = 0, j = 0;
//	float time = 0;
//	float time_hero = 0;
//	int death = 0, boom_x = 0, boom_y = 0;
//	int CurrentFrame = 0;
//	int CurrentFrame_1 = 0;
//	int isPressed = 0;
//	int bullets_array[350] = { 0 };
//	string aaa;
//
//	Font font;
//	font.loadFromFile("16606.ttf");
//
//	SoundBuffer shootbuffer;
//	shootbuffer.loadFromFile("sound\\10.ogg");
//	Sound shoot(shootbuffer);
//
//	Music music_game;
//	music_game.openFromFile("sound\\03.ogg");
//
//	Music music_game_over;
//	music_game_over.openFromFile("sound\\14.ogg");
//
//	Text text_1("Time:", font, 20);
//	Text text_3("", font, 20);
//	Text text_2("Made by Vlados_Bro", font, 10);
//	//-----Створюємо список------
//	list <BaseOfSubject*> EnemyObjects;
//	list <BaseOfSubject*>::iterator it_1;
//
//	list <Cloud*> CloudsObjects;
//	list <Cloud*>::iterator it_2;
//
//	list <Bullet*> BulletsObjects;
//	list <Bullet*>::iterator it_3;
//
//	//---------------------------
//
//	//-----Завантаження текстури моря-----
//	Image image_map;
//	Texture texture_map;
//	Sprite sprite_map;
//	//------------------------------------
//
//	image_map.loadFromFile("images\\ocean_map_2048x4096.png");
//	texture_map.loadFromImage(image_map);
//	sprite_map.setTexture(texture_map);
//
//	//---Створення Об'єктів---
//	Map map("images\\ocean_map_2048x4096.png", 0, 0, 1280, 704);
//	MapsCorner Corner0("break.png");
//	MapsCorner Corner1("break.png");
//	MapsCorner Corner2("break.png");
//	MapsCorner Corner3("break.png");
//
//	Spidometer spidometer("spidometr.png", "spidometr.png", 0, 0, 192, 112, 0, 0, 192, 112);
//
//	PanelList panel_list("ttt.png", "ttt.png", 0, 0, 400, 0);
//
//	for (i = 0; i < 10; i++)
//	{
//		CloudsObjects.push_back(new Cloud("clouds.png"));
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		CloudsObjects.push_back(new Cloud("clouds.png"));
//	}
//
//	Player Hero("Sprite_for_hero_test_1.png", 1.0, 1.0, 460, 520, 72, 72);
//
//	Image enemy_1_image;
//	enemy_1_image.loadFromFile("images\\enemy_1.png");
//
//	for (i = 0; i < 10; i++)
//	{
//		EnemyObjects.push_back(new Enemy(1, enemy_1_image, 250, -250, 64, 64, 0.1, 1, 2, 4, true, 5000, true, "enemy_1"));
//	}
//
//	//------------------------\\
//
//	Event event;
//	RenderWindow window(VideoMode(1280, 704, 64), "NES TIME");
//	Clock clock; // часова змінна
//
//
//	music_game.play();
//
//	//-----Початок роботи Основної Програми-----
//	//:::::::::::::::::::::::::::::::::::::::://
//
//	while (window.isOpen())
//	{
//		time = clock.getElapsedTime().asMicroseconds();
//		clock.restart();
//		time /= 1000;
//		timer += time;
//		if (AAA == 1)
//		{
//			timer_1 = timer / 1000;
//			aaa = to_string(timer_1);
//		}
//
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//			{
//				window.close();
//			}
//		}
//
//		//:::::::::::::::::::::::::::::::::::::::://
//
//
//		float CurrentTime = 0;
//
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//			{
//				window.close();
//			}
//
//			if (Keyboard::isKeyPressed(Keyboard::Space))
//			{
//				shoot.play();
//				isPressed = 1;
//				BulletsObjects.push_back(new Bullet("bullet.png", 1.0, 1.0, Hero.get_x() + 27, Hero.get_y() + 25, 72, 72, Hero.get_dir()));
//			}
//		}
//
//		window.clear();
//
//		//////////////////
//		//////////////////
//		//////////////////
//		if (Hero.get_Life() == true)
//		{
//			Hero.StandartMove(time);
//			Hero.StandartAnimation(time, 0);
//		}
//		//////////////////
//		//////////////////
//		//////////////////
//
//		for (it_1 = EnemyObjects.begin(); it_1 != EnemyObjects.end(); it_1++)
//		{
//
//			if ((*it_1)->get_pause() <= 0)
//			{
//				if ((*it_1)->get_Life() == false)
//				{
//					//Анімація смерті 
//					(*it_1)->add_Frame(time);
//					(*it_1)->StandartAnimation(time, 1);
//					/*window.draw((*it_1)->ReturnSprite());
//					window.draw((*it_3)->ReturnSprite());*/
//					if ((*it_1)->get_Frame() > 450)
//					{
//						(*it_1)->set_Frame(0);
//						(*it_1)->CheckKill(time);
//					}
//
//				}
//				else
//				{
//					(*it_1)->StandartMove(time);
//					(*it_1)->StandartAnimation(time, 0);
//					/*	window.draw((*it_1)->ReturnSprite());
//						window.draw((*it_3)->ReturnSprite());*/
//				}
//			}
//			else
//			{
//				(*it_1)->decrement_pause(time);
//			}
//
//		}
//		for (it_3 = BulletsObjects.begin(); it_3 != BulletsObjects.end(); it_3++)
//		{
//
//			(*it_3)->BulletMove(time);
//		}
//
//
//		if (Hero.get_Life() == false)
//		{
//			//Анімація смерті 
//			Hero.add_Frame(time);
//			Hero.StandartAnimation(time, 1);
//			/*window.draw(Hero.ReturnSprite());*/
//			if (Hero.get_Frame() > 500)
//			{
//				Hero.set_Frame(0);
//				window.draw(Hero.ReturnSprite());
//			}
//			if (flag == 0)
//			{
//				music_game.pause();
//				music_game_over.play();
//				flag = 1;
//			}
//
//
//		}
//
//
//		for (it_1 = EnemyObjects.begin(); it_1 != EnemyObjects.end(); it_1++)
//		{
//			if ((*it_1)->getRect().intersects(Hero.getRect()))
//			{
//				if ((*it_1)->get_name() == "enemy_1")
//				{
//					if ((*it_1)->get_atack() == true)
//					{
//						(*it_1)->SetDamage(time);
//						Hero.SetDamage(time);
//
//						window.draw((*it_1)->ReturnSprite());
//						window.draw(Hero.ReturnSprite());
//						break;
//					}
//				}
//			}
//
//		}
//
//		for (it_3 = BulletsObjects.begin(); it_3 != BulletsObjects.end(); it_3++)
//		{
//			for (it_1 = EnemyObjects.begin(); it_1 != EnemyObjects.end(); it_1++)
//			{
//				if ((*it_1)->getRect().intersects((*it_3)->getRect()))
//				{
//					(*it_1)->SetDamage(time);
//					(*it_3)->set_Life(0);
//					(*it_3)->bull();
//					window.draw((*it_1)->ReturnSprite());
//					window.draw(Hero.ReturnSprite());
//					break;
//				}
//			}
//		}
//
//
//
//		for (it_2 = CloudsObjects.begin(); it_2 != CloudsObjects.end(); it_2++)
//		{
//			(*it_2)->SpawnAndMove(time);
//		}
//
//
//		map.MapMove(time);
//		window.draw(map.ReturnSprite());
//
//		for (it_3 = BulletsObjects.begin(); it_3 != BulletsObjects.end(); it_3++)
//		{
//			window.draw((*it_3)->ReturnSprite());
//		}
//
//		for (it_1 = EnemyObjects.begin(); it_1 != EnemyObjects.end(); it_1++)
//		{
//			window.draw((*it_1)->ReturnSprite());
//		}
//		window.draw(Hero.ReturnSprite());
//
//		for (it_2 = CloudsObjects.begin(); it_2 != CloudsObjects.end(); it_2++)
//		{
//			window.draw((*it_2)->ReturnSprite());
//		}
//
//		//-----Малюємо рамку-----
//		for (int i = 0; i < HEIGHT_MAP; i++)
//		{
//			for (int j = 0; j < WIDTH_MAP; j++)
//			{
//				if (TileMap[i][j] == '0')
//				{
//					map.map_break_sprite_setTextureRect_break();
//				}
//				if (TileMap[i][j] == ' ')
//				{
//					map.map_break_sprite_setTextureRect_space();
//				}
//				if (TileMap[i][j] == '1')
//				{
//					map.map_break_sprite_setTextureRect_1();
//				}
//				if (TileMap[i][j] == '2')
//				{
//					map.map_break_sprite_setTextureRect_2();
//				}
//				if (TileMap[i][j] == '3')
//				{
//					map.map_break_sprite_setTextureRect_3();
//				}
//				if (TileMap[i][j] == '4')
//				{
//					map.map_break_sprite_setTextureRect_4();
//				}
//				if (TileMap[i][j] == '5')
//				{
//					map.map_break_sprite_setTextureRect_5();
//				}
//				if (TileMap[i][j] == '6')
//				{
//					map.map_break_sprite_setTextureRect_6();
//				}
//				if (TileMap[i][j] == '7')
//				{
//					map.map_break_sprite_setTextureRect_7();
//				}
//				if (TileMap[i][j] == '8')
//				{
//					map.map_break_sprite_setTextureRect_8();
//				}
//				if (TileMap[i][j] == '9')
//				{
//					map.map_break_sprite_setTextureRect_9();
//				}
//
//				map.map_break_sprite.setPosition(j * 32, i * 32);
//
//
//				window.draw(map.Return_map_break_sprite());
//
//			}
//		}
//		//------------------------\\
//
//		spidometer.SetText_1();
//		spidometer.SetText_2(Hero.get_size_life());
//		spidometer.Set_Pos_1(1042, 50);
//		spidometer.Set_Pos_2(1042, 55);
//
//		window.draw(spidometer.ReturnSprite());
//		window.draw(spidometer.ReturnSprite_2());
//
//		panel_list.SetText_1(time);
//		panel_list.SetText_2(time);
//		panel_list.Set_Pos_1(1073, 200);
//		panel_list.Set_Pos_2(1084, 208);
//		panel_list.Light(Hero.get_size_life(), time);
//
//		window.draw(panel_list.ReturnSprite_2());
//		window.draw(panel_list.ReturnSprite());
//		window.draw(panel_list.ReturnSprite_3());
//
//		Corner0.TypeOfSprite(0); // Малюю "кутові стрічки"
//		Corner1.TypeOfSprite(1);
//		Corner2.TypeOfSprite(2);
//		Corner3.TypeOfSprite(3);
//
//		text_1.setPosition(1045, 550);
//		window.draw(text_1);
//		text_3.setPosition(1045, 580);
//		text_3.setString(aaa);
//		window.draw(text_3);
//
//		text_2.setPosition(1040, 650);
//		window.draw(text_2);
//
//		window.draw(Corner0.ReturnSprite());
//		window.draw(Corner1.ReturnSprite());
//		window.draw(Corner2.ReturnSprite());
//		window.draw(Corner3.ReturnSprite());
//
//		window.display();
//	}
//	//------------------------------\\
//
//	return 0;
//}
