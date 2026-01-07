/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:05:17 by hamel-yo          #+#    #+#             */
/*   Updated: 2026/01/07 16:12:33 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H

# define MEMORY_MSG "no space left\n"

# include <stdbool.h>

bool	get_perror(char *s);
void	parsing_error(char *s);
void	*gc(size_t size);
#endif
