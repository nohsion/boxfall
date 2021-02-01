#include <stdio.h>
#include <stdlib.h>

void calculateBox(int * box, int n);
int searchMax(int * box, int n);

int main(void) {
    int n, m; // // 방의 가로 길이 n, 세로 길이 m
    scanf("%d %d", &n, &m);

    int * box_height = (int *)malloc(n*sizeof(int));

    // box_height 입력받아 거꾸로 저장
    for(int i=0; i<n; i++) {
        scanf("%d", &box_height[n-i-1]);
        if(box_height[i] > m) {
            printf("%d보다 큰 박스 높이를 입력했습니다!\n", m);
            return 1; // 에러. 프로그램 종료.
        }
    }

    // box_height 출력
    printf("box의 높이 : ");
    for(int i=0; i<n; i++) {
        printf("%d ", box_height[i]);
    }
    printf("\n");

    calculateBox(box_height, n);

    // 계산된 후 box_height(이때는 낙하거리임) 출력
    printf("box의 낙하거리 : ");
    for(int i=0; i<n; i++) {
        printf("%d ", box_height[i]);
    }
    printf("\n");

    // 가장 큰 낙하거리 출력(최종 결과)
    printf("가장 큰 낙하거리 : %d\n", searchMax(box_height, n));

    free(box_height); // 동적할당 해제
    return 0;
}

void calculateBox(int * box, int n) {
    int * box_temp = (int *)malloc(n*sizeof(int));
    int high=0;

    for(int i=0; i<n; i++) {
        if(box[i] == 0 || i==0) { // 높이가 0이거나 가장 오른쪽 박스는 낙하거리가 0임.
            box_temp[i] = 0;
            continue;
        }
        for(int j=0; j<i; j++) {
            if(box[i] <= box[j]) { // 자기 자신(i번째)보다 크거나 같은 박스높이를 찾음
                high++;
            }
            box_temp[i] = i - high;
        }
        high = 0;
    }

    for(int i=0; i<n; i++) {
        box[i] = box_temp[i];
    }

    free(box_temp);
}

// 배열에서 가장 큰 값 찾는 함수
int searchMax(int * box, int n) {
    int max = -1;
    for(int i=0; i<n; i++) {
        if(box[i] > max) {
            max = box[i];
        }
    }
    return max;
}
