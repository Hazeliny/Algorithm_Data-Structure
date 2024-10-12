/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrackFrm.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:00:53 by linyao            #+#    #+#             */
/*   Updated: 2024/10/12 15:00:57 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* backtrack frame */
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
