#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <ctype.h>        // 문자 종류를 판별하기 위함
#include <string.h>        // strcpy를 사용하기 위함
 
void main(void);
void Receipt(int, char);
void Receipt_fin(int, char);
 
// 전역 변수 선언 및 초기화
// (관리자 모드에서 볼 커피 재고)
int co1 = 50, co2 = 50, co3 = 50, co4 = 50;
// (총 매출)
int sum = 0, co1_cnt = 0, co2_cnt = 0, co3_cnt = 0, co4_cnt = 0;
int co1_sum = 0, co2_sum = 0, co3_sum = 0, co4_sum = 0;
 
//자판기를 종료할 건지 물어보는 함수
void Finish()
{
    char choice;
 
    printf("정말 자판기 프로그램을 종료하시겠습니까? (종료 : y, 계속 실행 : n)\n");
    printf("입력 : ");
    scanf(" %c", &choice);
 
    if (choice == 'y' || choice == 'Y') {
        printf("\n<< 자판기 프로그램을 종료합니다. 감사합니다. >>\n");
 
        //자판기 프로그램 종료
        exit(0);
    }
    else if (choice == 'n' || choice == 'N') {
        printf("\n<< 자판기 프로그램을 계속 실행합니다. >>\n\n");
 
        main();
    }
    else {
        printf("\n<< 보기에 없는 키를 입력하셨습니다. 다시 선택해주십시오. >>\n\n");
 
        //자판기 프로그램을 종료할 건지 물어보는 함수를 다시 호출
        Finish();
    }
}
 
// 관리자 모드
int Admin()
{
    char select;
    int i, coffee, count;
 
    printf("\n");
    for (i = 0; i < 51; i++) {
        printf("=");
    }
    printf("\n\n관리자 모드로 진입하셨습니다.\n\n");
 
    // 커피 잔량 표시
    printf("======= 커피 재고 현황 =======\n");
    printf("  1. Regular coffee : %d개\n  2. Special coffee : %d개\n  3. Sugar coffee   : %d개\n  4. Black coffee   : %d개\n", co1, co2, co3, co4);
    for (i = 0; i < 30; i++) {
        printf("=");
    }
 
    // 관리자 모드 기능 소개
    printf("\n\n원하는 기능을 선택해주세요.\n");
    printf("1. 커피 재고 채우기\n2. 커피 재고 빼기\n3. 총 매출 결산 확인\nx. 종료\n");
    
    // 실행할 관리자 기능 선택
    printf("\n------> 선택 : ");
    scanf(" %c", &select);
 
    switch (select) {
    case '1':
        // 커피 재고 채우기
        printf("\n<< 커피 재고를 채웁니다. 재고를 충전할 커피와 수량을 입력해주세요. >>\n\n");
        printf("======== 메뉴 선택 ========\n");
        printf("    1. Regular coffee\n    2. Special coffee\n    3. Sugar coffee\n    4. Black coffee\n");
        for (i = 0; i < 27; i++) {
            printf("=");
        }
        printf("\n------> 재고를 채울 커피 번호 입력 : ");
        scanf("%d", &coffee);
        printf("\n------> 재고를 채울 수량 입력 : ");
        scanf("%d", &count);
 
        switch (coffee) {
        case 1:
            co1 += count;
 
            break;
        case 2:
            co2 += count;
 
            break;
        case 3:
            co3 += count;
 
            break;
        case 4:
            co4 += count;
 
            break;
        }
 
        break;
    case '2':
        // 커피 재고 빼기
        printf("\n<< 커피 재고를 뺍니다. 재고를 뺄 커피와 수량을 입력해주세요. >>\n\n");
        printf("======== 메뉴 선택 ========\n");
        printf("    1. Regular coffee\n    2. Special coffee\n    3. Sugar coffee\n    4. Black coffee\n");
        for (i = 0; i < 27; i++) {
            printf("=");
        }
        printf("\n------> 재고를 뺄 커피 번호 입력 : ");
        scanf("%d", &coffee);
        printf("\n------> 재고를 뺄 수량 입력 : ");
        scanf("%d", &count);
 
        switch (coffee) {
        case 1:
            co1 -= count;
 
            break;
        case 2:
            co2 -= count;
 
            break;
        case 3:
            co3 -= count;
 
            break;
        case 4:
            co4 -= count;
 
            break;
        }
 
        break;
    case '3':
        // 총 매출 결산 확인
        printf("\n<< 총 매출 : %d원 >>\n\n", sum);
 
        printf("====== 커피 종류별 판매량 ======\n");
        printf("  1.   Regular coffee   :   %d개\n  2.   Special coffee   :   %d개\n  3.   Sugar coffee     :   %d개\n  4.   Black coffee     :   %d개\n", co1_cnt, co2_cnt, co3_cnt, co4_cnt);
        for (i = 0; i < 32; i++) {
            printf("=");
        }
 
        printf("\n\n====== 커피 종류별 판매 금액 ======\n");
        printf("  1.   Regular coffee   :   %d원\n  2.   Special coffee   :   %d원\n  3.   Sugar coffee     :   %d원\n  4.   Black coffee     :   %d원\n", co1_sum, co2_sum, co3_sum, co4_sum);
        for (i = 0; i < 35; i++) {
            printf("=");
        }
 
        break;
    case 88:
    case 120:
        printf("\n<< 관리자 모드를 종료합니다. >>\n\n");
        for (i = 0; i < 60; i++) {
            printf("=");
        }
        printf("\n\n");
 
        // 자판기 프로그램 일반 모드로 진입해서 다시 실행
        main();
        break;
    default:
        printf("\n<< 보기에 없는 기능을 입력하셨습니다. >>\n\n");
 
        // 다시 관리자 모드 진입
        Admin();
        break;
    }
 
    Admin();
}
 
//자판기의 돈을 투입받는 함수
int Money(int temp)
{
    int money;
 
    while (1)
    {
        printf("\n돈을 투입하세요. (10원 단위로 1000원까지 투입 가능합니다.)\n(종료를 원하시면 'x'를 입력해주세요.)\n");
        printf("투입 : ");
        //사용자가 입력한 것이 숫자가 아니라 문자일 경우
        if (scanf(" %d", &money) == 0)
        {
            printf("\n");
 
            money = getchar();
            //입력한 문자가 'x'일 경우
            if (money == 'x' || money == 'X') {
                printf("<< 투입하셨던 %d원을 받아가세요. >>\n\n", temp);
                rewind(stdin);
                Finish();
            }
            else {
                printf("<< 잘못된 문자를 입력하셨습니다. >>\n\n");
 
                rewind(stdin);
                main();
            }
        }
 
        // 관리자 모드로 진입
        if (money == 920712) {
            Admin(co1, co2, co3, co4);
        }
 
        //투입 금액이 10원 단위가 아닐 때, 1000원보다 클 때 다시 투입
        if (money % 10 != 0 || money > 1000) {
            printf("\n<< 10원 단위로 돈을 투입해주셔야 합니다. 돈을 다시 투입해주세요. >>\n\n");
 
            continue;
        }
 
        printf("\n");
 
        return money;
    }
}
 
//자판기의 메뉴와 가격을 보여주는 함수
int Start()
{
    int money = 0, i;
 
    while (1)
    {
        printf("안녕하세요.\n커피 자동 판매기입니다. (Ver 1.0)\n\n");
        printf("======== 메뉴 & 가격 ========\n");
        printf("  1. Regular coffee : 300원\n  2. Special coffee : 500원\n  3. Sugar coffee   : 300원\n  4. Black coffee   : 300원\n");
        for (i = 0; i < 29; i++) {
            printf("=");
        }
 
        money = Money(money);    //사용자로부터 돈을 투입받는 함수 호출
 
        printf("\n");
 
        return money;
    }
}
 
//사용자가 메뉴를 선택하는 함수
int Choice(int money, int count)
{
    char menu = '1';
    char available[] = "[선택가능]", Not_available[] = "[선택불가]";
    char co1_ok[11], co2_ok[11], co3_ok[11], co4_ok[11];
    int plus = 0, price = 0, i;
    
    // 사용자가 투입한 돈에 따라 커피의 구매가능 여부를 출력
    while ('0' < menu && menu < '5')
    {
        // 투입한 금액에 따라 커피구매 가능 여부 설정
        if (money >= 500) {                    // 투입한 금액이 500원 이상일 때 모두 구매 가능
            strcpy(co1_ok, available);
            strcpy(co2_ok, available);
            strcpy(co3_ok, available);
            strcpy(co4_ok, available);
        }
        else if (money >= 300 && money < 500) {        // 투입한 금액이 300원 이상 500원 미만일 때
            strcpy(co1_ok, available);
            strcpy(co2_ok, Not_available);            // Special coffee 빼고 구매 가능
            strcpy(co3_ok, available);
            strcpy(co4_ok, available);
        }
        else if (money < 300) {                        // 투입한 금액이 300원 미만일 때 모두 구매 불가능
            strcpy(co1_ok, Not_available);
            strcpy(co2_ok, Not_available);
            strcpy(co3_ok, Not_available);
            strcpy(co4_ok, Not_available);
        }
 
        // 재고가 없을 때 커피 구매가 불가능 설정
        if (co1 < 1)
            strcpy(co1_ok, Not_available);
        if (co2 < 1)
            strcpy(co2_ok, Not_available);
        if (co3 < 1)
            strcpy(co3_ok, Not_available);
        if (co4 < 1)
            strcpy(co4_ok, Not_available);
 
        if (count != 1)
            printf("=== -> 투입 금액 : %d원\n\n", money);        //돈을 투입해서 커피를 구매할 경우
        else
            printf("=== -> 잔액 : %d원\n\n", money);        //잔액으로 커피를 추가구매할 경우
 
        //사용자에게 메뉴 선택화면 출력
        printf("================ 메뉴 선택 ================\n");
        printf("   1. Regular coffee : 300원  %s\n   2. Special coffee : 500원  %s\n", co1_ok, co2_ok);
        printf("   3. Sugar coffee   : 300원  %s\n   4. Black coffee   : 300원  %s\n", co3_ok, co4_ok);
        for (i = 0; i < 43; i++) {
            printf("=");
        }
 
        //투입한 돈으로 커피를 하나도 살 수 없는 경우
        if (money < 300) {
            printf("\n투입하신 돈으로 커피를 살 수 없습니다.\n");
            plus = Money(money);
            money += plus;        //추가로 받은 돈을 원래 투입받은 돈과 합산함
        }
 
        printf("\n메뉴를 선택해주세요. (Regular coffee를 원한다면 '1'을 입력해주세요.)\n");
        printf("===-> 입력 : ");
        //메뉴를 입력
        scanf(" %c", &menu);
        
        //사용자가 선택한 메뉴에 따라 커피를 출력해줌
        switch (menu) {
        case '1':
            if (money < 300 || co1 < 1)
                break;
 
            printf("\n=== -> OUTPUT : Regular coffee\n\n");
 
            co1--;
            co1_cnt++;
            co1_sum += 300;
 
            break;
        case '2':
            if (money < 500 || co2 < 1)
                break;
 
            printf("\n=== -> OUTPUT : Special coffee\n\n");
 
            co2--;
            co2_cnt++;
            co2_sum += 500;
 
            break;
        case '3':
            if (money < 300 || co3 < 1)
                break;
 
            printf("\n=== -> OUTPUT : Sugar coffee\n\n");
 
            co3--;
            co3_cnt++;
            co3_sum += 300;
 
            break;
        case '4':
            if (money < 300 || co4 < 1)
                break;
 
            printf("\n=== -> OUTPUT : Black coffee\n\n");
 
            co4--;
            co4_cnt++;
            co4_sum += 300;
 
            break;
        default:
            printf("\n<< 보기에 없는 메뉴를 입력하셨습니다. >>\n\n");
 
            Choice(money, count);
        }
 
        //돈을 더 투입 받아서 커피를 샀을 경우에
        if (plus > 0)
        {
            price = menu - 48;
            Receipt_fin(money, price);        //영수증을 출력하는 함수 호출
 
            main();        //영수증이 두 번 출력되는 경우를 막기 위해 메인함수 호출
        }
 
        return menu;
    }
}
 
//영수증을 출력하는 함수
void Receipt_fin(int money, char menu)
{
    int change, count, price = 0, i;
    char select;
 
    if (menu != '2')
        price = 300;
    else
        price = 500;
 
    sum += price;
    change = money - price;
 
    printf("\n===== 거래 명세 영수증 =====\n");
    printf("     입력한 돈 : %d원\n", money);
    printf("     계산금액  : %d원\n", price);
    printf("     거스름돈  : %d원\n", change);
    for (i = 0; i < 28; i++) {
        printf("=");
    }
    
    //커피를 더 살 수 있으면 사용자에게 커피를 더 살건지 물어봄
    if (change >= 300) {
        printf("\n\n잔액으로 커피를 더 구매하시겠습니까?\n(구매를 원하시면 'Y', 구매를 하지 않고 거스름돈 반환을 원하시면 'N'을 입력해주세요.)\n");
        printf("입력 : ");
        scanf(" %c", &select);
 
        if (select == 'Y' || select == 'y') {
            printf("\n<< 잔액으로 커피를 더 구매합니다. >>\n\n");
 
            count = 1;
            menu = Choice(change, count);            //사용자가 잔액으로 커피 구매를 원할 경우 메뉴선택 함수를 호출
 
            Receipt(change, menu);        //영수증을 출력하기 위한 함수를 호출
        }
        else if (select == 'N' || select == 'n') {
            printf("\n<< 거스름돈 %d원을 반환해드렸습니다. 자판기의 처음 시작으로 돌아갑니다. >>\n\n", change);
            
            //입력버퍼를 비우고 자판기의 처음 시작인 main함수로 돌아감
            rewind(stdin);
            main();
        }
        else {
            printf("\n<< 보기에 없는 키를 입력하셨습니다. >>\n\n");
 
            //다시 영수증을 출력하는 함수인 자기 자신을 호출
            Receipt_fin(money, price);
        }
    }
    else {                //커피를 두 개 이상 구매한 사용자일 때, 자판기가 종료될 때 나오는 메시지를 출력
        printf("\n\n\n<< 자판기 프로그램이 종료되었습니다. 거스름돈 %d원을 받아가세요. >>\n", change);
        printf("<< 이용해주셔서 감사합니다. >>");
    }
 
    printf("\n\n");
}
 
//영수증을 출력하기 위해 준비하는 함수
void Receipt(int money, char menu)
{
    int i, price, change, plus;
    char select;
 
    //선택한 메뉴에 따른 가격 정의
    if (menu == '2')
        price = 500;
    else
        price = 300;
 
    //거스름돈 계산
    change = money - price;
    
    if (change < 0) {        //투입한 돈으로 커피를 사지 못하는 경우
        printf("\n돈이 부족합니다. 추가로 돈을 더 투입하시면 커피를 구매하실 수 있습니다.\n");
        printf("추가로 돈을 더 투입하시겠습니까?\n(추가로 돈 투입을 원하시면 'Y', 자판기 종료를 원하시면 'N'을 입력해주세요.)\n");
        printf("입력 : ");
        scanf(" %c", &select);
 
        if (select == 'Y' || select == 'y') {        //사용자가 돈을 더 투입하길 원할 경우
            printf("\n돈을 더 투입해주세요.\n");
            printf("투입 : ");
            scanf("%d", &plus);
            money += plus;
        }
        else if (select == 'N' || select == 'n') {            //사용자가 자판기 종료를 원할 경우
            printf("\n<< 자판기 프로그램을 종료합니다. 투입했던 %d원을 받아가세요. >>\n<< 자판기를 이용해주셔서 감사합니다. >>\n\n", money);
 
            //자판기 프로그램 종료
            exit(0);
        }
        else {            //사용자가 Y나 N 외의 잘못된 문자를 입력했을 경우
            printf("<< 잘못된 문자를 입력하셨습니다. 투입했던 %d원을 받아가세요. >>\n<< 자판기 프로그램을 처음부터 다시 시작합니다. >>\n\n", money);
 
            //입력버퍼를 비우고 자판기를 다시 시작함
            rewind(stdin);
            main();
        }
 
        Receipt_fin(money, menu);        //영수증을 출력하는 함수 호출
    }
    else {        //투입한 금액으로 정상적으로 커피를 샀을 경우
        // 재고가 없을 경우 영수증 출력 안 하고 넘어감
        if (co1 < 1 || co2 < 1 || co3 < 1 || co4 < 1) {
            printf("\n<< 죄송합니다. 재고가 없습니다. 다른 커피를 이용해주세요. >>\n");
            for (i = 0; i < 60; i++) {
                printf("=");
            }
            printf("\n");
 
            main();
        }
 
        Receipt_fin(money, menu);        //영수증을 출력하는 함수 호출
    }
 
    printf("\n\n");
}
 
void main()
{
    int money, count = 0;
    char menu;
 
    while (1)
    {
        money = Start();    //돈 투입받는 함수 호출
        menu = Choice(money, count);        //메뉴 선택하는 함수 호출
        Receipt(money, menu);        //영수증 출력하는 함수 호출
    }
 
    return 0;
}
