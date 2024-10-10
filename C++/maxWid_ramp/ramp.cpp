/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ramp.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:01:16 by linyao            #+#    #+#             */
/*   Updated: 2024/10/10 23:29:11 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
// monotonic stack
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