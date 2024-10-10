/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onepass_hashtable.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:12:43 by linyao            #+#    #+#             */
/*   Updated: 2024/10/10 20:39:24 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unordered_map>

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