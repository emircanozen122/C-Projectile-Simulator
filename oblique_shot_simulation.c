#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// variables decrlaration
struct vector2
{
    double x;
    double y;
};
struct Ball
{
    struct vector2 position;
    struct vector2 speed;
};
// variables decrlaration


//function declaration
void printObliqueShotPoitns(char *screen ,int screenWidth,int screenHeight);
void printPosSpeed(const struct Ball *ball, double timeOfFlight);
char* createScreen(int w, int h);
char* fillScreenWithPoints(char *screen, int screenWidth, int screenHeight, double maxWidth,double maxHeight,double *xCoords, double *yCoords, int pointCount);
double angleToRadian(double angle);
void calcMaxHeightAndWidth(double firstPositionX,double firstPositionY,double firstSpeedX,double firstSpeedY,double gravity,double* outMaxWidth,double * outMaxHeight,double *outTimeOfFlight);
void simulationOfObliqueShot(struct Ball *ball,double positionX, double positionY,double firstSpeed,double shotAngle,double deltaTime,double gravity);
//function declaration


int main()
{
    struct Ball *ball= (struct Ball*) malloc(sizeof(struct Ball));
    if (ball == NULL) {
        printf("Bellek hatasi: Yeterli alan yok!\n");
        return EXIT_FAILURE;
    }
   simulationOfObliqueShot(ball,0,0,20,30,0.1,10);
    free(ball);
    return 0;
}

void simulationOfObliqueShot(struct Ball *ball,double positionX, double positionY,double firstSpeed,double shotAngle,double deltaTime,double gravity){
    double timeOfFlight = .0;
     char* screen = createScreen(100, 60);    
     
    printf("Oblique Shot Simulation\n");
     printf("Enter first cordinate-X: ");scanf("%lf",&positionX);
     printf("Enter first cordinate-Y: ");scanf("%lf",&positionY);
    printf("Enter first speed: ");scanf("%lf",&firstSpeed);
    printf("Enter shot degree: ");scanf("%lf",&shotAngle);
    ball->position.x = positionX;
    ball->position.y = positionY;
    shotAngle = angleToRadian(shotAngle);
    double firstSpeedX=firstSpeed * cos(shotAngle);
    double firstSpeedY=firstSpeed * sin(shotAngle);
    double maxWidth,maxHeight,totalTimeOfFlight;
    
    calcMaxHeightAndWidth(positionX,positionY,firstSpeedX,firstSpeedY,gravity,&maxWidth,&maxHeight,&totalTimeOfFlight);
    
    int pointsNumber = totalTimeOfFlight / deltaTime;
    
    int maxPoints = pointsNumber + 5; 
    double *ballCordinatesX = (double*)malloc(maxPoints * sizeof(double));
    double *ballCordinatesY = (double*)malloc(maxPoints * sizeof(double));


    //double ballCordinates[2][pointsNumber+10];
    ballCordinatesX[0]=positionX;
    ballCordinatesY[0]=positionY;
    
    ball->speed.x = firstSpeedX;
    ball->speed.y = firstSpeedY;
    
    printPosSpeed(ball, timeOfFlight);
     int k=1;
    while (ball->position.y >= 0)
    {
        
        ball->position.x += ball->speed.x * deltaTime;
        ball->position.y += (ball->speed.y * deltaTime) - gravity * pow(deltaTime, 2) / 2;
        
       
       if (k < maxPoints) {
        ballCordinatesX[k] = ball->position.x;
        ballCordinatesY[k] = ball->position.y;
        k++;
    }
         
        ball->speed.y -= gravity * deltaTime;
        timeOfFlight += deltaTime;
        printPosSpeed(ball, timeOfFlight);
    }
    
        printf("\n\n");
        fillScreenWithPoints(screen, 100, 60,maxWidth , maxHeight, ballCordinatesX,  ballCordinatesY, k);
        
        printObliqueShotPoitns(screen, 100, 60);

    free(screen);
    
}

void printPosSpeed(const struct Ball *ball, double timeOfFlight)
{
    printf("PosX: %lf PosY: %lf \t SpeedX: %lf SpeedY: %lf \t Time: %lf\n", ball->position.x, ball->position.y, ball->speed.x, ball->speed.y, timeOfFlight);
}

char* createScreen(int w, int h) {
    int totalCells = w * h;
    char* screen = (char*) malloc(totalCells * sizeof(char));
    
    // Güvenlik Kontrolü
    if (screen == NULL) return NULL; 

    for(int i = 0; i < totalCells; i++) {
        *(screen + i) = ' '; // İçini tertemiz boşlukla doldur
    }
    return screen; 
}
char* fillScreenWithPoints(char *screen, int screenWidth, int screenHeight, double maxWidth, double maxHeight, double *xCoords, double *yCoords, int pointCount) {
    double scaleX = (double)screenWidth / maxWidth;
    double scaleY = (double)screenHeight / maxHeight;

    // 1. ADIM: ZEMİN (Döngü dışında, bir kez)
    for (int j = 0; j < screenWidth; j++) {
        int index = ((screenHeight - 1) * screenWidth) + j;
        *(screen + index) = '-';
    }

    int start_y_scaled = (int)(yCoords[0] * scaleY);

    if (start_y_scaled > 0) {
        int start_row = (screenHeight - 1) - start_y_scaled;
        for (int i = start_row; i < screenHeight - 1; i++) {
            int index = (i * screenWidth) + 0;
            if (index >= 0 && index < (screenWidth * screenHeight)) {
                *(screen + index) = '|';
            }
        }
    }

    // 3. ADIM: YILDIZLAR (Bağımsız, ayrı bir döngü)
    for (int k = 0; k < pointCount; k++) {
        int draw_x = (int)(*(xCoords + k) * scaleX - 0.5);
        int draw_y = (int)(*(yCoords + k) * scaleY - 0.5);

        if (draw_x >= screenWidth) draw_x = screenWidth - 1;
        if (draw_x < 0) draw_x = 0;
        if (draw_y >= screenHeight) draw_y = screenHeight - 1;
        if (draw_y < 0) draw_y = 0;

        int targetIndex = ((screenHeight - 1 - draw_y) * screenWidth) + draw_x;

        if (targetIndex >= 0 && targetIndex < (screenWidth * screenHeight)) {
            *(screen + targetIndex) = '*';
        }
    }

    return screen;
}

void printObliqueShotPoitns(char *screen, int screenWidth,int screenHeight){
    
     for(int i=0;i<screenHeight;i++){
        for(int j=0;j<screenWidth;j++){
         int index = (i * screenWidth) + j;
         printf("%c", *(screen + index));
        }
        printf("\n");
    }
}

double angleToRadian(double angle)
{
    return M_PI * angle / 180;
}

void calcMaxHeightAndWidth(double firstPositionX,double firstPositionY,double firstSpeedX,double firstSpeedY,double gravity,double* outMaxWidth,double * outMaxHeight,double *outTimeOfFlight){
    double maxHeight= pow(firstSpeedY/gravity,2)*gravity/2+firstPositionY;
    double timeOfFlight= firstSpeedY / gravity + sqrt(2*maxHeight/gravity);
    double maxWidth= firstSpeedX * timeOfFlight;
    *outMaxWidth=maxWidth;
    *outMaxHeight =maxHeight;
    *outTimeOfFlight=timeOfFlight;
    printf("\nmaxWidth: %lf, maxHeight: %lf, time: %lf\n\n",maxWidth,maxHeight,timeOfFlight);
}










