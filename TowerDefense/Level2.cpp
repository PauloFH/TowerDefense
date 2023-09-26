#include "Level2.h"
#include "Enemy.h"
#include "Tower.h"
#include "TowerDefense.h"
#include "Rain.h"
#include <random>
#include "Button.h"
#include "Floor.h"
#include "Grass.h"


std::random_device rd;
std::mt19937 gen(rd());

Scene* Level2::scene = nullptr;
void Level2::Init() {

	tilesetCenoura = new TileSet("Resources/cenoura.png", 40, 50, 8, 30);
	tilesetBatata = new TileSet("Resources/batata.png", 40, 50, 8, 30);
	tilesetCebola = new TileSet("Resources/cebola.png", 40, 50, 8, 30);
	tilesetNabo = new TileSet("Resources/nabo.png", 40, 50, 8, 30);
	tilesetBrocolis = new TileSet("Resources/brocolis.png", 40, 50, 8, 30);
	tilesetCheiroVerde = new TileSet("Resources/cheiroverde.png", 40, 50, 8, 30);
	tilesetMilho = new TileSet("Resources/milho.png", 40, 50, 8, 30);
	tilesetAlface = new TileSet("Resources/alface.png", 40, 50, 8, 30);
	tilesetCouveFlor = new TileSet("Resources/couveflor.png", 40, 50, 8, 30);

	tilesetRain = new TileSet("Resources/rain.png", 12, 12, 3, 3);

	ground = new Sprite("Resources/ground.png");
    floor = new Sprite("Resources/oldFloor.png");

	scene = new Scene();
	TowerDefense::scene = scene;
	scene->Add(TowerDefense::mouse, MOVING);
	scene->Add(TowerDefense::hub, STATIC);
    scene->Add(TowerDefense::priest, STATIC);

    if (TowerDefense::souls < 3) {
        TowerDefense::souls = 3;
    }

	Button* button1 = new Button(REDB);
	Button* button2 = new Button(PURPLEB);
	Button* button3 = new Button(BLUEB);
	Button* button4 = new Button(YELLOWB);
	Button* button5 = new Button(GREENB);

	scene->Add(button1, STATIC);
	scene->Add(button2, STATIC);
	scene->Add(button3, STATIC);
	scene->Add(button4, STATIC);
	scene->Add(button5, STATIC);

	Enemy* brocolis = new Enemy(tilesetBrocolis, BROCOLIS);
	scene->Add(brocolis, MOVING);

	rainTimerStarter = true;

    // ----------------------------------
    //        Defini��o de rota
    // ----------------------------------
    int posicaoX = -48;
    int posicaoY = 360;
    Floor* chao = new Floor(floor, posicaoX, posicaoY);
    scene->Add(chao, STATIC);
    for (int i = 0; i < 2; i++) {
        posicaoX = posicaoX + 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }
    for (int i = 0; i < 2; i++) {
        posicaoY = posicaoY + 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    for (int i = 0; i < 4; i++) {
        posicaoX = posicaoX + 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    for (int i = 0; i < 4; i++) {
        posicaoY = posicaoY - 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    for (int i = 0; i < 3; i++) {
        posicaoX = posicaoX - 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    for (int i = 0; i < 2; i++) {
        posicaoY = posicaoY - 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    for (int i = 0; i < 5; i++) {
        posicaoX = posicaoX + 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    for (int i = 0; i < 3; i++) {
        posicaoY = posicaoY + 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    for (int i = 0; i < 2; i++) {
        posicaoX = posicaoX + 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    for (int i = 0; i < 3; i++) {
        posicaoY = posicaoY + 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    for (int i = 0; i < 3; i++) {
        posicaoX = posicaoX + 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    for (int i = 0; i < 5; i++) {
        posicaoY = posicaoY - 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    for (int i = 0; i < 2; i++) {
        posicaoX = posicaoX + 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    // ----------------------------------
    //        Resto dos pisos
    // ----------------------------------
    Sprite* flowerFloor = new Sprite("Resources/darkFlowerFloor.png");
    Sprite* basicFloor = new Sprite("Resources/darkFloor.png");

    int n68 = -68;
    posicaoY = posicaoY + (68 * 6);
    posicaoX = posicaoX + 68;
    for (int i = 1; i <= 144; i++) {
        if (i == 3 || i == 22 || i == 36 || i == 51 || i == 55 || i == 58 || i == 66 || i == 78 || i == 86 || i == 91 || i == 101 || i == 121 || i == 131 || i == 132 || i == 140 || i == 143) {
            chao = new Floor(flowerFloor, posicaoX, posicaoY, true);
        }
        else {
            chao = new Floor(basicFloor, posicaoX, posicaoY, true);
        }
        if (i == 5 || i == 41 || i == 66 || i == 83 || i == 123) {
            Grass* tomb = new Grass(posicaoX, posicaoY, 40);
            scene->Add(tomb, STATIC);
        }
        if (i == 35 || i == 53 || i == 102) {
            Grass* tomb = new Grass(posicaoX, posicaoY, 41);
            scene->Add(tomb, STATIC);
        }
        if (i == 60 || i == 108) {
            Grass* tomb = new Grass(posicaoX, posicaoY, 42);
            scene->Add(tomb, STATIC);
        }
        scene->Add(chao, STATIC);
        posicaoX = posicaoX + n68;
        if (i % 16 == 0) {
            posicaoY = posicaoY - 68;
            n68 = -n68;
        }
    }

    // ------------------------------------------------------------------------------------
    //                DEFINI��O DOS DIRECTIONS POINTS PRA ESSA FASE
    // ------------------------------------------------------------------------------------

    DirectionPoint* point1 = new DirectionPoint(UP);
    point1->MoveTo(window->CenterX() - 360, window->CenterY() + 20);    // -395 � bem no meio (do primeiro)
    scene->Add(point1, STATIC);

    DirectionPoint* point2 = new DirectionPoint(RIGHT);
    point2->MoveTo(window->CenterX() - 393, window->CenterY() - 218);
    scene->Add(point2, STATIC);

    DirectionPoint* point3 = new DirectionPoint(DOWN);
    point3->MoveTo(window->CenterX() - 220, window->CenterY() - 183);
    scene->Add(point3, STATIC);

    DirectionPoint* point4 = new DirectionPoint(RIGHT);
    point4->MoveTo(window->CenterX() - 258, window->CenterY() + 192);
    scene->Add(point4, STATIC);

    DirectionPoint* point5 = new DirectionPoint(UP);
    point5->MoveTo(window->CenterX() - 88, window->CenterY() + 159);
    scene->Add(point5, STATIC);

    DirectionPoint* point6 = new DirectionPoint(RIGHT);
    point6->MoveTo(window->CenterX() - 120, window->CenterY() - 148);
    scene->Add(point6, STATIC);

    DirectionPoint* point7 = new DirectionPoint(UP);
    point7->MoveTo(window->CenterX() + 115, window->CenterY() - 115);
    scene->Add(point7, STATIC);

    DirectionPoint* point8 = new DirectionPoint(RIGHT);
    point8->MoveTo(window->CenterX() + 83, window->CenterY() - 285);
    scene->Add(point8, STATIC);

    DirectionPoint* point9 = new DirectionPoint(DOWN);
    point9->MoveTo(window->CenterX() + 320, window->CenterY() - 252);
    scene->Add(point9, STATIC);

    DirectionPoint* point10 = new DirectionPoint(LEFT);
    point10->MoveTo(window->CenterX() + 287, window->CenterY() + 55);
    scene->Add(point10, STATIC);

    DirectionPoint* point11 = new DirectionPoint(DOWN);
    point11->MoveTo(window->CenterX() + 50, window->CenterY() + 20);
    scene->Add(point11, STATIC);

    DirectionPoint* point12 = new DirectionPoint(RIGHT);
    point12->MoveTo(window->CenterX() + 85, window->CenterY() + 192);
    scene->Add(point12, STATIC);

}

void Level2::Finalize() {
	delete tilesetCenoura;
	delete tilesetBatata;
	delete tilesetCebola;
	delete tilesetNabo;
	delete tilesetBrocolis;
	delete tilesetCheiroVerde;
	delete tilesetMilho;
	delete tilesetAlface;
	delete tilesetCouveFlor;
	delete tilesetRain;
	scene->Remove(TowerDefense::mouse, MOVING);
	scene->Remove(TowerDefense::hub, STATIC);
    scene->Remove(TowerDefense::priest, STATIC);
	delete scene;
	delete ground;
}

void Level2::Update() {

	// ----------------------------
	// Ambienta��o da chuva
	// ----------------------------

	if (rainTimerStarter) {
		rainTimer.Start();
		rainTimerStarter = false;
	}
	else {
		if (rainTimer.Elapsed(0.05)) {
			Rain* rain = new Rain(tilesetRain, random(0, 2));
			// � bom espalhar mais, definir mais intervalos mais fechados
			rain->MoveTo(random(0, window->Width() + 500), 0);
			scene->Add(rain, STATIC);

			rainTimerStarter = true;
			rainTimer.Reset();
		}
	}


	scene->Update();
    scene->DrawBBox();
	scene->CollisionDetection();
}

void Level2::Draw() {
	ground->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
	scene->Draw();
}


int Level2::random(int low, int high)
{
	std::uniform_int_distribution<> dist(low, high);
	return dist(gen);
}