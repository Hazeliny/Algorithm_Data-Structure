/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twoPointer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:05:16 by linyao            #+#    #+#             */
/*   Updated: 2024/10/17 15:03:44 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

/*
归并排序
*/
class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i = m - 1;
            int j = n - 1;
            int k = m + n -1;

            while (j >= 0) {
                if (i >= 0 && nums1[i] > nums2[j]) {
                    nums1[k--] = nums1[i--];
                } else {
                    nums1[k--] = nums2[j--];
                }
            }
        }
};