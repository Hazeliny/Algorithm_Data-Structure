/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiffEle_Full_Permute.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 00:02:15 by linyao            #+#    #+#             */
/*   Updated: 2024/05/27 00:37:48 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 交换两个字符
void    ft_swap(char *x, char *y)
{
    char    temp;

    temp = *x;
    *x = *y;
    *y = temp;
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
            ft_swap((str +left), (str + i));
            ft_fullPermute(str, left + 1, right);
            ft_swap((str + left), (str + i)); // 还原字符串
        }
    }
}

int main(void)
{
    char    str[] = "ABC";
    int n = strlen(str);
    ft_fullPermute(str, 0, n - 1);
    return (0);
}
// 此程序只适用于处理无重复元素的全排列
// 此代码不适用于处理包含重复元素的字符串，因为它会生成重复的排列