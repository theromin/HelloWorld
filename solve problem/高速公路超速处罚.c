/*
按照规定，在高速公路上行使的机动车，达到或超出本车道限速的10%则处200元罚款；
若达到或超出50%，就要吊销驾驶证。请编写程序根据车速和限速自动判别对该机动车的处理。
*/
#include <stdio.h>
#include <math.h>
int main ()
{
	double cs,xs,cc;//车速，限速，超出 
	scanf("%lf%lf",&cs,&xs);
	cc=(cs-xs)/xs;
	if(cc<0.1) printf("OK");
	else if(cc<0.5) printf("Exceed %.0f%%. Ticket 200",cc*100);
	else printf("Exceed %.0f%%. License Revoked",cc*100);
  return 0;
}
