//head
#include <stdio.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
float years, mounths, ANyears, ANmounths, days;
long long int ANdays, hours, minutes, seconds, tm_years, tm_mounths, tm_days, sec, min, hou, md, mon, yea;

//SYSTEMtime
/**
 * @brief
 *
 * #include <time.h>
 *
 * struct tm * gmtime(const time_t *clock);
 *
 * gmtime()将参数 clock 所指的 time_t 结构中的信息转换成真实世界 所使用的时间日期表示方法，然后将结果由结构 tm 返回。结构 tm 的定义为:
	struct tm {
		int tm_sec;
		int tm_min;
		int tm_hour;
		int tm_mday;
		int tm_mon;
		int tm_year;
		int tm_wday;
		int tm_yday;
		int tm_isdst;
	};

int tm_sec 代表目前秒数，正常范围为 0-59，但允许至 61 秒
int tm_min 代表目前分数，范围 0-59
int tm_hour 从午夜算起的时数，范围为 0-23
int tm_mday 目前月份的日数，范围 01-31
int tm_mon 代表目前月份，从一月算起，范围从 0-11
int tm_year 从 1900 年算起至今的年数
int tm_wday 一星期的日数，从星期一算起，范围为 0-6
int tm_yday 从今年 1 月 1 日算起至今的天数，范围为 0-365 int tm_isdst 日光节约时间的旗标 此函数返回的时间日期未经时区转换，而是 UTC 时间。

*/
void time_tm() {
	time_t timep;
	time(&timep);

	// printf("%s\n", ctime(&timep));

	struct tm* p;
	p = gmtime(&timep);

	sec = p->tm_sec;         /*获取当前秒*/
	min = p->tm_min;         /*获取当前分*/
	hou = 8 + p->tm_hour;    /*获取当前时,这里获取UTC时间,中国是UTC+8*/
	md = p->tm_mday;        /*获取当前月份日数,范围是1-31*/
	mon = 1 + p->tm_mon;     /*获取当前月份,范围是0-11,所以要加1*/
	yea = 1900 + p->tm_year; /*获取当前年份,从1900开始，所以要加1900*/
}

//questions
void questions() {
	
	//year 
	printf("enter your upyear: \n");
	scanf("%f", &years);
	while (1) {
		if (years <= 0 || years >= yea) {
			printf("this year is a joke,please try again: \n");
			scanf("%f", &years);
		}
		else {
			return;
		}
	}
	
	//mounth
	printf("enter your upmounth: \n");
	scanf("%f", &mounths);
	while (1) {
		if (mounths <= 0 || mounths > 12) {
			printf("this mounths is a joke,please try again: \n");
			scanf("%f", &mounths);
		}
		else {
			return;
		}
	}
	
	//day
	printf("enter your upday: \n");
	scanf("%f", &days);
	while (1) {
		if (days <= 0 || days > 31) {
			printf("this days is a joke,please try again: \n");
			scanf("%f", &days);
		}
		else {
			return;
		}
	}

}

//answers
void answers() {
	ANyears = +yea - years;
	ANmounths = mon + ANyears * 12;
	ANdays = md + 365 * ANyears;
	hours = hou + 24 * ANdays;

	printf("you are life %f years \n", ANyears);
	printf("you are life %f mounths \n", ANmounths);
	printf("you are life %llu days \n", ANdays);
	printf("you are life %llu hours \n", hours);

}
int main(void) {
	time_tm();
	questions();
	answers();




}















