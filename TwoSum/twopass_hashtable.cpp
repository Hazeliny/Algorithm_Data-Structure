/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twopass_hashtable.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:22:35 by linyao            #+#    #+#             */
/*   Updated: 2024/10/10 12:22:44 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unordered_map>

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> numMap;
            int n = nums.size();

            for (int i = 0; i < n; i++) {
                numMap[nums[i]] = i;
            }
            for (int i = 0; i < n; i++) {
                int complement = target - nums[i];
                if (numMap.count(complement) && numMap[complement] != i) {
                    return {i, numMap[complement]};
                }
            }
            return {};
        }
}
