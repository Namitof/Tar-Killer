#include "ColisionManager.h"

#include <raylib.h>

#include <cmath>

#include "Player.h"

#include "Bullet.h"

#include "Enemy.h"

namespace ColisionManager
{
	bool CollisionCircleCircle(Vector2 centerC1, float radiusC1, Vector2 centerC2, float radiusC2);


	bool CollisionCircleCircle(Vector2 centerC1, float radiusC1, Vector2 centerC2, float radiusC2)
	{
		/*
			Chequeo de colisiones de circulo a circulo
			Datos -> Centro (x, y) de cada circulo
				  -> Radio (Radius) de cada circulo
		*/

		//Cateto A
		float a = centerC2.x - centerC1.x;
		if (a < 0)
		{
			a *= -1;
		}

		//Cateto B
		float b = centerC2.y - centerC1.y;
		if (b < 0)
		{
			b *= -1;
		}

		//Hipotenusa
		float c = (a * a) + (b * b);

		float sumRadius = radiusC1 + radiusC2;

		return ((sumRadius * sumRadius) >= c);
	}

	void ScreenBorderCollision(float& posX, float& posY, float radius, int width, int height)
	{
		const int MIN_POS_X = 0;
		const int MIN_POS_Y = 0;

		// Chequeo colision de player con los bordes de la pantalla
		if (posX + radius < MIN_POS_X)
		{
			posX = width + radius;
		}
		else if (posX - radius > width)
		{
			posX = MIN_POS_X - radius;
		}

		if (posY + radius < MIN_POS_Y)
		{
			posY = height + radius;
		}
		else if (posY - radius > height)
		{
			posY = MIN_POS_Y - radius;
		}
	}

	void CheckColisions(Player::Player& player, Bullet::Bullet bullets[Bullet::MAX_BULLETS], Enemy::Enemy enemys[Enemy::MAX_ENEMYS], int width, int height, int& enemyCountEliminated)
	{
		// Chequeo colision de player con los bordes de la pantalla
		ScreenBorderCollision(player.pos.x, player.pos.y, player.radius, width, height);

		// Chequeo colision de bullets con los bordes de la pantalla
		for (int i = 0; i < Bullet::MAX_BULLETS; i++)
		{
			if (bullets[i].isActive)
			{
				ScreenBorderCollision(bullets[i].pos.x, bullets[i].pos.y, bullets[i].radius, width, height);
			}
		}

		// Chequeo colision de enemys con los bordes de la pantalla
		for (int i = 0; i < Enemy::MAX_ENEMYS; i++)
		{
			if (enemys[i].isActive)
			{
				ScreenBorderCollision(enemys[i].pos.x, enemys[i].pos.y, enemys[i].radius, width, height);
			}
		}

		bool inCollision = false;

		// Chequeo colision de las balas con los obstaculos
		for (int i = 0; i < Bullet::MAX_BULLETS; i++)
		{
			if (bullets[i].isActive)
			{
				for (int j = 0; j < Enemy::MAX_ENEMYS; j++)
				{
					if (enemys[j].isActive)
					{
						inCollision = CollisionCircleCircle(enemys[j].pos, enemys[j].radius, bullets[i].pos, bullets[i].radius);
						if (inCollision)
						{
							enemys[j].isActive = false;
							bullets[i].isActive = false;
							player.score++;

							if (enemys[j].size == Enemy::EnemySize::Large)
							{
								enemyCountEliminated++;
							}

							int quantity = 0;

							Vector2 spawnPos = enemys[j].pos;

							spawnPos.x += 10;
							
							while (quantity < 2)
							{
								switch (enemys[j].size)
								{
								case Enemy::EnemySize::Large:

									Enemy::AddEnemyInPool(enemys, Enemy::EnemySize::Medium, spawnPos, Enemy::GenerateRandomDirection()/*{ 1.0f, 1.0f }*/);

									quantity++;

									spawnPos = enemys[j].pos;
									spawnPos.x -= 10;
									break;

								case Enemy::EnemySize::Medium:
									Enemy::AddEnemyInPool(enemys, Enemy::EnemySize::Small, spawnPos, Enemy::GenerateRandomDirection());
									quantity++;

									spawnPos = enemys[j].pos;
									spawnPos.x -= 10;

									break;

								case Enemy::EnemySize::Small:
									quantity = 2;
									break;

								default:
									break;
								}
							}

							//while (quantity < 2)
							//{
							//	switch (enemys[j].size)
							//	{
							//	case Enemy::EnemySize::Large:
							//		enemyCountEliminated++;

							//		for (int k = 0; k < Enemy::MAX_ENEMYS; k++)
							//		{
							//			if (!enemys[k].isActive)
							//			{
							//				Enemy::Init(enemys[k], Enemy::EnemySize::Medium);
							//				Enemy::SetPos(enemys[k], spawnPos);
							//				Enemy::SetDireccion(enemys[k], { 1.0f, 1.0f });

							//				enemys[k].isActive = true;

							//				quantity++;

							//				spawnPos = enemys[j].pos;
							//				spawnPos.x -= 10;
							//			}
							//		}

							//		break;
							//	case Enemy::EnemySize::Medium:

							//		for (int k = 0; k < Enemy::MAX_ENEMYS; k++)
							//		{
							//			if (!enemys[k].isActive)
							//			{
							//				Enemy::Init(enemys[k], Enemy::EnemySize::Small);
							//				Enemy::SetPos(enemys[k], spawnPos);
							//				Enemy::SetDireccion(enemys[k], { 1.0f, 1.0f });

							//				enemys[k].isActive = true;
							//				quantity++;

							//				spawnPos = enemys[j].pos;
							//				spawnPos.x -= 10;
							//			}
							//		}

							//		break;
							//	case Enemy::EnemySize::Small:
							//		//
							//		break;
							//	default:
							//		break;
							//	}
							//}

							//switch (enemys[j].size)
							//{
							//case Enemy::EnemySize::Large:
							//	enemyCountEliminated++;

							//	while (quantity < 2)
							//	{
							//		for (int k = 0; k < Enemy::MAX_ENEMYS; k++)
							//		{
							//			if (!enemys[k].isActive)
							//			{
							//				Enemy::Init(enemys[k], Enemy::EnemySize::Medium);
							//				Enemy::SetPos(enemys[k], spawnPos);
							//				Enemy::SetDireccion(enemys[k], {1.0f, 1.0f});

							//				enemys[k].isActive = true;

							//				quantity++;

							//				spawnPos = enemys[j].pos;
							//				spawnPos.x -= 10;
							//			}
							//		}

							//	}

							//	break;
							//case Enemy::EnemySize::Medium:

							//	while (quantity < 2)
							//	{
							//		for (int k = 0; k < Enemy::MAX_ENEMYS; k++)
							//		{
							//			if (!enemys[k].isActive)
							//			{
							//				Enemy::Init(enemys[k], Enemy::EnemySize::Small);
							//				Enemy::SetPos(enemys[k], spawnPos);
							//				Enemy::SetDireccion(enemys[k], { 1.0f, 1.0f });

							//				enemys[k].isActive = true;
							//				quantity++;

							//				spawnPos = enemys[j].pos;
							//				spawnPos.x -= 10;
							//			}
							//		}

							//	}

							//	break;
							//case Enemy::EnemySize::Small:
							//	//
							//	break;
							//default:
							//	break;
							//}

							break;
						}
					}
				}
				if (inCollision)
				{
					break;
				}
			}
		}

		// Chequeo colision del player con los enemigos
		for (int i = 0; i < Enemy::MAX_ENEMYS; i++)
		{
			if (enemys[i].isActive)
			{
				if (CollisionCircleCircle(player.pos, player.radius, enemys[i].pos, enemys[i].radius))
				{
					/*player.pos.x += enemys[i].direction.x;
					player.pos.y += enemys[i].direction.y;

					player.lifes--;*/

					float obstacleCenterX = enemys[i].pos.x;
					float obstacleCenterY = enemys[i].pos.y;

					float obstacleMinX = obstacleCenterX - enemys[i].radius;
					float obstacleMaxX = obstacleCenterX + enemys[i].radius;
					float obstacleMinY = obstacleCenterY - enemys[i].radius;
					float obstacleMaxY = obstacleCenterY + enemys[i].radius;

					float maxX = player.pos.x + player.radius;
					float minX = player.pos.x - player.radius;

					float maxY = player.pos.y + player.radius;
					float minY = player.pos.y - player.radius;

					float diffX = 0.0f;
					float diffY = 0.0f;

					if (maxX < obstacleCenterX) //golpea de izquierda
					{
						diffX = obstacleMinX - maxX;
					}
					else if (minX > obstacleCenterX) //golpea de derecha
					{
						diffX = obstacleMaxX - minX;
					}

					if (minY > obstacleCenterY) //golpea de arriba
					{
						diffY = maxY - obstacleMaxY;
					}
					else if (maxY < obstacleCenterY) //golpea de abajo
					{
						diffY = minY - obstacleMinY;
					}

					//float absDiffX = abs(diffX);
					//float absDiffY = abs(diffY);

					/*if (absDiffX < absDiffY)
					{
						player.pos.x += diffX;
					}
					else
					{
						player.pos.y += diffY;
					}*/
					player.pos.x += diffX;

					player.pos.y += diffY;


					//int margin = 2;

					/*if (player.pos.x >= obstacles[i][j].hitbox.minPosition.x - margin && player.pos.x <= obstacles[i][j].hitbox.minPosition.x + obstacles[i][j].hitbox.width + margin)
					{
						ball.dir.y *= -1;
					}
					else if (player.pos.y >= obstacles[i][j].hitbox.minPosition.y - margin && player.pos.y <= obstacles[i][j].hitbox.minPosition.y + obstacles[i][j].hitbox.height + margin)
					{
						ball.dir.x *= -1;
					}
					else
					{
						ball.dir.x *= -1;
						ball.dir.y *= -1;
					}*/

					//player.lifes--;
					enemys[i].isActive = false;

					if (enemys[i].size == Enemy::EnemySize::Large)
					{
						enemyCountEliminated++;

					}
					break;
				}
			}
		}

	}
}
