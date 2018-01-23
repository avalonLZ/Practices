/************************************************************************
	> File Name: bridge_vhdis.c
	> Author:lizhong 
	> Mail: 
	> Created Time: 2018年01月17日 星期三 17时37分36秒
 ************************************************************************/
/*该函数用于计算地图上某点到地图上某线的距离*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdarg.h>
#include<math.h>

#define EARTH_RADIUS 6371.004
#define PI 3.1415926

#define VHREA_LAT 60*228958//纬度
#define VHREA_LON 60*1132131//

#define VHSENDB_LAT 60*228983
#define VHSENDB_LON 60*1132142

double get_radian(long degree)
{
	return (degree / 10000.0 / 60.0 / 180.0 * PI);
}

double TwoPointDis(long lng1, long lat1, long lng2, long lat2)
{
	double rlng1 = get_radian(lng1);
	double rlat1 = get_radian(lat1);
	double rlng2 = get_radian(lng2);
	double rlat2 = get_radian(lat2);

	double drlng = rlng2 - rlng1;
	double drlat = rlat2 - rlat1;
	
	double a = sin(drlat/2)*sin(drlat/2)+cos(rlat1)*cos(rlat2)*sin(drlng/2)*sin(drlng/2);
	double c = 2 * atan2(sqrt(a), sqrt(1 - a));
	return (c * EARTH_RADIUS);
}

int main()
{
    double hl = 0.0, dis = 0.0;
    double a = 0.0, b = 0.0, c= 0.0;
    double A = 0.0,B = 0.0,C = 0.0;
    long int temp = 0;
    long int pointclat = 60;
    long int pointclon = 60;
    
    while(1)
    {
        a = b = c = 0.0;
        A = B = C = 0.0;
        hl = dis = 0.0;
        temp = 0;
        pointclon = pointclat = 60;

        printf("\r\n请输入经纬度数据，例:\
               \r\n原始纬度:22.8969xxxx-->输入纬度:228969\
               \r\n原始经度:113.2130xxxx-->输入经度:1132130\r\n");
        printf("坐标点纬度 = ");
        scanf("%ld", &temp);
        getchar();
        pointclat *= temp;
        printf("坐标点经度 = ");
        scanf("%ld", &temp);
        getchar();
        pointclon *= temp;

        c = TwoPointDis(VHREA_LON, VHREA_LAT, VHSENDB_LON, VHSENDB_LAT)*1000.0;
        a = TwoPointDis(VHSENDB_LON, VHSENDB_LAT, pointclon, pointclat)*1000.0;
        b = TwoPointDis(pointclon, pointclat, VHREA_LON, VHREA_LAT)*1000.0;

        A = acos((b*b+c*c-a*a)/(2*b*c))*180/PI;
        B = acos((c*c+a*a-b*b)/(2*c*a))*180/PI;
        C = acos((a*a+b*b-c*c)/(2*a*b))*180/PI;
        
        printf("a = %.2lfm, b = %.2lfm, c = %.2lfm\r\nA = %.2f, B = %.2f, C = %.2f, Zong = %lf\r\n"
               , a, b, c, A, B, C, (A + B + C));
        
        //保证是三角形,存在计算误差，实际值略大于180
        if((A + B + C) > 180.00)
        { 
            hl = (a + b + c)/2.0;
            dis = sqrt(hl * (hl - a)*(hl - b)*(hl - c)) * 2.0 / c;
            printf("该点到定义线距离为:%.2lfm\r\n", dis);
        }
        else
        {
            printf("该点在定义线上，dis = 0m\r\n");
        }
    }
}

