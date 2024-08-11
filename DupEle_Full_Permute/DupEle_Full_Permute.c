/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DupEle_Full_Permute.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 00:18:41 by linyao            #+#    #+#             */
/*   Updated: 2024/05/27 00:35:40 by linyao           ###   ########.fr       */
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

// 检查字符是否在当前范围内已经使用过
bool    ft_shouldSwap(char str[], int start, int curr)
{
    for (int    i = start; i < curr; i++)
    {
        if (str[i] == str[curr])
        {
            return (false);
        }
    }
    return (true);
}

// 递归函数生成排列
void    ft_fullPermute(char *str, int left, int right)
{
    if (left == right)
    {
        printf("%s\n", str);
    }
    else
    {
        for (int    i = left; i <= right; i++)
        {
            // 只有在当前范围内未出现过的字符才进行交换
            if (ft_shouldSwap(str, left, i))
            {
                ft_swap((str + left), (str + i));
                ft_fullPermute(str, left + 1, right);
                ft_swap((str + left), (str + i)); // 还原字符串
            }
        }
    }
}

int main(void)
{
    char    str[] = "AAB";
    int n = strlen(str);
    ft_fullPermute(str, 0, n - 1);
    return (0);
}
// 此代码适用于包含重复元素的字符串的不重复的全排列
// 也适用于无重复元素的字符串全排列