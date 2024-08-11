/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EqualEle_Pruning_Permutation.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:23:06 by linyao            #+#    #+#             */
/*   Updated: 2024/06/13 12:52:20 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void    ft_swap(char *x, char *y)
{
    char    temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

// 回溯函数递归生成所有不重复排列
void    ft_backtrack(char *str, int left, int right, bool *used)
{
    if (left == right)
    {
               printf("%s\n", str);
    }
    else
    {
        bool    duplicated[256] = {false}; // 用于剪枝相同元素
        for (int    i = left; i <= right; i++)
        {
            if (!used[i] && !duplicated[(unsigned char)str[i]])
            {
                // duplicated数组用于剪枝相同元素，避免横向同一层递归中相等字符被重复选择
                duplicated[(unsigned char)str[i]] = true;
                ft_swap(&str[left], &str[i]);
                used[left] = true; // used数组用于剪枝已选择的元素，避免纵向重复选择
                ft_backtrack(str, left + 1, right, used);
                used[left] = false;
                ft_swap(&str[left], &str[i]);
            }
        }  
    }
}

void    ft_fullPermuteUnique(char *str)
{
    int n = strlen(str);
    bool    *used = (bool *)calloc(n, sizeof(bool));
    ft_backtrack(str, 0, n - 1, used);
    free(used);
}

int main(void)
{
    char    str[] = "AAB";
    ft_fullPermuteUnique(str);
    return (0);
}
/*
这种方法确保生成的全排列不包含重复项，适用于有重复元素的字符数组全排列
也适用于无重复元素的全排列
*/