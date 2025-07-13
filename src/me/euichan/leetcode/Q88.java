package me.euichan.leetcode;

import java.util.Arrays;

public class Q88 {

    /**
     * https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
     *
     * non-decreasing order: 숫자가 감소하지 않고 같거나 커지는 순서
     * 중요한 단서: 정렬되어 있다.
     */
    public void merge1(int[] nums1, int m, int[] nums2, int n) {
        for (int i = 0; i < n; i++) { // O(n)
            nums1[m + i] = nums2[i];
        }

        Arrays.sort(nums1); // O(nlog(n)) , 즉 O(m+n log(m+n))
        // 따라서 시간복잡도는 O((m+n) log(m+n))이 된다.
    }

    public void merge2(int[] nums1, int m, int[] nums2, int n) {
        int p1 = m - 1; // nums1의 실제 데이터 마지막 인덱스
        int p2 = n - 1; // nums2의 마지막 인덱스
        int i = m + n - 1; // nums1 배열의 가장 마지막 인덱스

        while (p2 >= 0) {
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[i] = nums1[p1];
                p1--;
            } else {
                nums1[i] = nums2[p2];
                p2--;
            }
            i--;
        }
    }
}
