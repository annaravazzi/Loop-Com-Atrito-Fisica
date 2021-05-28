#include <stdio.h>
#include <math.h>
#define PI 3.14159
#define G 9.81
///variacoes do angulo e da altura
#define DTHETA 0.0001
#define DH 0.0001

int main()
{
	float massa = 0.41, raio = 0.32, coef_atrito = 0.37, 	///informacoes do exercicio
			altura = 2.5 * raio, 	///inicializando a altura como a altura minima sem atrito
			en_cin, en_cin0, theta, y, normal, trab_atrito, u_grav;

	do
	{
		altura += DH;
		en_cin0 = massa * G * altura;	///energia cinetica inicial (antes do atrito)
		trab_atrito = 0.0;				///inicializando o trabalho do atrito (inicio do loop)

		for(theta = 0.0; theta <= PI; theta += DTHETA)		///da parte mais baixa ate a mais alta do loop
		{
			y = raio * (1 - cos(theta));			///altura do bloco
			u_grav = massa * G * y;					///energia potencial gravitacional em funcao de y

			en_cin = en_cin0 - u_grav - trab_atrito;		///decrescimo da energia cinetica a partir da inicial
			if (en_cin < 0.0)		///energia cinetica nao pode ser negativa
				break;

			normal = massa*G*cos(theta) + 2.0*en_cin/raio;	///normal atual
			if(normal < 0.0)
				break;

			trab_atrito += coef_atrito * normal * raio * DTHETA;		///acumula o trabalho do atrito ao longo do loop
		}

	}while (normal < 0.0 || en_cin < 0.0);

	printf("\n\n%f m\n\n", altura);

	return 0;
}