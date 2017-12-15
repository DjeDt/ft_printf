/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_final.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:29:28 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/15 12:11:14 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	final_concat(t_core *core, void *to_add)
{
	char	*new;

	new = NULL;
	core->bytes += ft_strlen(to_add);
	new = ft_strjoin(core->final, to_add);
	if (core->final)
		free(core->final);
	core->final = new;
	if (to_add)
		free(to_add);
}
