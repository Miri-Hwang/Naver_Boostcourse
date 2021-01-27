#include <stdio.h>
#include <stdlib.h>

const int NUMBER_OF_GRADES = 9; // 학점 등급 갯수
const char *GRADES[NUMBER_OF_GRADES] = {"A+", "A", "B+", "B", "C+", "C", "D+", "D", "F"};
const int SCORES_STANDARD[NUMBER_OF_GRADES] = {95, 90, 85, 80, 75, 70, 65, 60, 0};

int check_validity(int value);
void show_grade(int value);

int main(void)
{
    int validity_result = 1;
    printf("학점프로그램\n종료를 원하면 \"999\"를 입력\n[학점 테이블]\n점수 : ");
    //학점 출력
    for (int i = 0; i < NUMBER_OF_GRADES; i++)
    {
        if (i == NUMBER_OF_GRADES - 1)
        {
            printf("%-4i     \n학점 : ", SCORES_STANDARD[i]);
            break;
        }
        printf("%-4i     ", SCORES_STANDARD[i]);
    }
    //점수 출력
    for (int i = 0; i < NUMBER_OF_GRADES; i++)
    {
        if (i == NUMBER_OF_GRADES - 1)
        {
            printf("%-3s     \n", GRADES[i]);
            break;
        }
        printf("%-3s      ", GRADES[i]);
    }

    while (1)
    {
        int grade;
        printf("성적을 입력하세요 (0~100) : ");
        scanf("%d", &grade);

        if (grade == 999) // 999를 입력하면 프로그램 종료
        {
            printf("학점 프로그램을 종료합니다.");
            break;
        }
        else
        {
            validity_result = check_validity(grade); // 점수가 유효한 값 범위 내에 있는 지 확인
            if (validity_result == 0)                // 유효한 경우
            {
                show_grade(grade); // 점수에 맞게 학점을 출력한다.
                continue;
            }
            else // 유효하지 않은 경우
            {
                continue;
            }
        }
    }

    return 0;
}

//값의 유효성을 체크하는 함수
int check_validity(int value)
{
    if (value >= 0 && value <= 100)
    {
        return 0; // 유효한 값이라면 리턴값은 0
    }
    else
    {
        printf("** %i 성적을 올바르게 입력하세요. 범위는 0 ~ 100 입니다.\n", value);
        return 1; // 유효하지 않은 값이라면 리턴값은 1
    }
}

//점수 채점 후 학점 출력 함수
void show_grade(int value)
{
    for (int i = 0; i < NUMBER_OF_GRADES; i++)
    {
        if (value >= SCORES_STANDARD[i])
        {
            printf("학점은 %s 입니다.\n", GRADES[i]);
            break;
        }
    }
}