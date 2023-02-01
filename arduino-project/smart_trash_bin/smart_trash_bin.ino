// LA POUBELLE INTELLIGENTE

// Quand j'approche ma main de la poubelle a moins de 12 centimetre, le capteur de distance percoit ma main.
// La poubelle s’ouvre a l'aide du servomoteur. La poubelle se referme 3 secondes apres l'ouverture du couvercle. 
// De cette facon, je peux jeter mes dechets sans toucher a la poubelle. 

#include <Servo.h>
#define echoPin 6     // J'ai defini echoPin et trigPin.
#define trigPin 7
Servo servomoteur;

void setup()
{
pinMode(trigPin,OUTPUT);     // j'ai fixe le trigPin comme la sortie.
pinMode(echoPin,INPUT);      // j'ai fixe l'echoPin comme l'entree.
servomoteur.attach(9);       // j'ai defini le servomoteur au pin numero 9.
Serial.begin (9600);         // J'ai commence la communication serie.
}

void loop()
{
float temps;       // J'ai cree les variables temps et distance.
float distance;

digitalWrite(trigPin,LOW);      // J'ai mis trigPin a la position low. J'ai fini d'envoyer le signal audio.
delayMicroseconds(2);        
digitalWrite(trigPin,HIGH);     // J'ai mis trigPin a la position high. J'ai commence d'envoyer de nouveaux signaux audio.
delayMicroseconds(2); 
digitalWrite(trigPin,LOW);      // J'ai mis trigPin a la position low. J'ai arrete d'envoyer le signal audio.

temps = pulseIn(echoPin,HIGH);  
distance = temps / 58.2;        

// Le temps est egal a la duree d'aller-retour du signal audio calculee avec la commande pulseIn.
// La vitesse du son en 1 microseconde est egale a 0,0343 (1 / 0,0343 = 29,1)
// Distance = Vitesse * Temps donc distance = temps /(29.1*2). J'ai divise par 2 car temps = duree d'aller-retour.
                                
if(distance < 12)               // Si la distance est inferieure a 12 centimetres, le couvercle de la poubelle ouvrira.
{ 
servomoteur.write(90);          // L’helice du servomoteur tourne a 90 degres et la poubelle s’ouvre a l'aide du morceau plastique que j’ai colle au servomoteur.
Serial.print("La distance: ");     // J'imprime la distance a l'ecran.
Serial.println(distance);  
Serial.println("La poubelle est ouverte");      //  J'imprime "La poubelle est ouverte" a l'ecran.
delay(3000);                                    // Il attend 3 secondes pour que les dechets soit jetes.
servomoteur.write(0);           // L'helice du servomoteur tourne a 90 degres dans la direction opposee et revient a sa position d'origine. Cela ferme le couvercle.
Serial.println("La poubelle est fermee");  // J'imprime "La poubelle est fermee" a l'ecran.
}
}