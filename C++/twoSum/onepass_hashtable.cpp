/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onepass_hashtable.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:12:43 by linyao            #+#    #+#             */
/*   Updated: 2024/10/17 15:15:52 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unordered_map>

/*
两数之和问题，即在一个整数数组 nums 中，找到两个不同的数，使它们的和等于目标值 target，并返回它们的下标。
如果找不到这样的两个数，则返回空数组。
*/
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int>numMap;
            int n = nums.size();

            for (int i = 0; i < n; i++) {
                int complement = target - nums[i];
                if (numMap.count(complement)) {
                    return {numMap[complement], i};
                }
                numMap[nums[i]] = i;
            }
            return {};
    }
};