/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrackFrm.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:00:53 by linyao            #+#    #+#             */
/*   Updated: 2024/10/17 15:09:59 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 回溯算法框架 backtrack frame */
void    backtrack(State *state, vector<Choice *> &choices, vector<State *> &res) {
    if (isSolution(state)) {
        // record the solution
        recordSolution(state, res);
        // stop searching
        return ;
    }

    // iterate all the choices
    for (Choice choice : choices) {
        // prune: judge if it is valid
        if (isValid(state, choice)) {
            // make a choice, update status
            makeChoice(state, choice);
            backtrack(state, choices, res);
            // undo: revoke the choice,restore to the previous status
            undoChoice(state, choice);
        }
    }
};
