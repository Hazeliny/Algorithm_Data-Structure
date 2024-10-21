/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ramp.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:01:16 by linyao            #+#    #+#             */
/*   Updated: 2024/10/17 15:13:45 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
// monotonic stack
/*
最大宽度坡度问题，给定一个整数数组 nums，找出满足条件的坡度 (i, j) 使得 nums[i] <= nums[j]
并且坡度的宽度 j - i 最大化
*/
class Solution {
    public:
        int maxWidthRamp(vector<int>& nums) {
            int n = nums.size();
            stack<int> s;
            // push part of indices into stack where the values are in descending order from bottom to top         
            for (int i = 0; i < n; i++) {
                if (s.empty() || nums[s.top()] > nums[i]) {
                    s.push(i);
                }
            }
            int maxWidth = 0;
            // iterate from right to left and pop indices from stack 
            // and calculate the width of the ramp when the values are in ascending order from top to bottom
            for (int j = n - 1; j >= 0; --j) {
                while (!s.empty() && nums[s.top()] <= nums[j]) {
                    maxWidth = max(maxWidth, j - s.top());
                    s.pop();
                }
            }
            return maxWidth;
        }
};