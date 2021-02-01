# boxfall

1. 미션 제목
가장 큰 낙하거리 찾기

2. 지시문
상자들이 쌓여있는 방이 있습니다. 방이 오른쪽으로 90도 회전하여 상자들이 중력의 영향을 받아 낙하한다고 할 때, 
낙하거리가 가장 큰 상자를 구하여 그 낙하거리를 출력하는 프로그램을 작성해 봅시다.
아래 그림에서 총 26개 상자가 회전 후, 오른쪽 그림과 같은 상태가 됩니다.
A상자의 낙하거리가 7로 가장 크므로 7을 출력하면 됩니다. 회전 결과, B 상자의 낙하거리는 6이고, C상자의 낙하거리는 1입니다.
중력은 회전이 완료된 이후에 적용되며, 상자들은 모두 한쪽 벽면에 붙여진 상태로 쌓여 2차원의 형태를 이루며 벽에서 떨어져서 쌓인 상자는 없습니다.
입력으로는 첫 줄에 각 방의 가로 길이 N(2 ≤ N ≤ 100)과 방의 세로 길이 M(2 ≤ N ≤ 100)이 주어지며, 다음 줄에는 N개의 상자들이 쌓여있는 높이 H(0 ≤ H ≤ M)가 주어집니다.
가장 직관적인 방법은 MxN내의 모든 box에 대해서 낙하거리를 계산한 뒤 정렬 알고리즘을 사용하여 최댓값을 찾으면 되는 문제라고 생각할 수 있습니다.
이 방법은 시간 복잡도(Big O)가 얼마나 될 지 먼저 생각해봅시다. 그리고, 이보다 더 효율적인 방법으로 프로그램을 작성해봅시다.
완전한 프로그램을 작성하는 것이 힘들 경우에는 pseudo code로 작성해도 좋습니다. 다만 이 경우에는 최대한 자세히 적어야 합니다.
숫자를 입력받는 부분은 따로 구현하지 않고 프로그램 내부에서 따로 선언하는 것으로 가정합니다.

 
예)
입력값:
9 8 // 방의 가로 길이 N, 세로 길이 M
7 4 2 0 0 6 0 7 0 // 상자들이 쌓여있는 높이
출력값:
7 // 가장 큰 낙하거리

 

3. 핵심 개념
# 최대값찾기
