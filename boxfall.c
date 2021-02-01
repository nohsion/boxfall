#include <stdio.h>
#include <stdlib.h>

void calculateBox(int * box, int n);
int searchMax(int * box, int n);

int main(void) {
    int n, m; // // ���� ���� ���� n, ���� ���� m
    scanf("%d %d", &n, &m);

    int * box_height = (int *)malloc(n*sizeof(int));

    // box_height �Է¹޾� �Ųٷ� ����
    for(int i=0; i<n; i++) {
        scanf("%d", &box_height[n-i-1]);
        if(box_height[i] > m) {
            printf("%d���� ū �ڽ� ���̸� �Է��߽��ϴ�!\n", m);
            return 1; // ����. ���α׷� ����.
        }
    }

    // box_height ���
    printf("box�� ���� : ");
    for(int i=0; i<n; i++) {
        printf("%d ", box_height[i]);
    }
    printf("\n");

    calculateBox(box_height, n);

    // ���� �� box_height(�̶��� ���ϰŸ���) ���
    printf("box�� ���ϰŸ� : ");
    for(int i=0; i<n; i++) {
        printf("%d ", box_height[i]);
    }
    printf("\n");

    // ���� ū ���ϰŸ� ���(���� ���)
    printf("���� ū ���ϰŸ� : %d\n", searchMax(box_height, n));

    free(box_height); // �����Ҵ� ����
    return 0;
}

void calculateBox(int * box, int n) {
    int * box_temp = (int *)malloc(n*sizeof(int));
    int high=0;

    for(int i=0; i<n; i++) {
        if(box[i] == 0 || i==0) { // ���̰� 0�̰ų� ���� ������ �ڽ��� ���ϰŸ��� 0��.
            box_temp[i] = 0;
            continue;
        }
        for(int j=0; j<i; j++) {
            if(box[i] <= box[j]) { // �ڱ� �ڽ�(i��°)���� ũ�ų� ���� �ڽ����̸� ã��
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

// �迭���� ���� ū �� ã�� �Լ�
int searchMax(int * box, int n) {
    int max = -1;
    for(int i=0; i<n; i++) {
        if(box[i] > max) {
            max = box[i];
        }
    }
    return max;
}
