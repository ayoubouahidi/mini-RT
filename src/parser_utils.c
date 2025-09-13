/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:26:03 by ayouahid          #+#    #+#             */
/*   Updated: 2025/09/13 17:26:05 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/parse.h"


t_lexer	*creat_lexer(char *content)
{
	t_lexer	*lexer;

	lexer = (t_lexer *)malloc(sizeof(t_lexer));
	if (!lexer)
		return (NULL);
	lexer->content = content;
	lexer->i = 0;
	lexer->c = lexer->content[lexer->i];
	return (lexer);
}

void	increment_using_index(t_lexer *lexer)
{
	if (lexer->c != '\0' && lexer->i < ft_strlen(lexer->content))
	{
		lexer->i += 1;
		lexer->c = lexer->content[lexer->i];
	}
}

t_token	*creat_token(char *value)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = value;
	token->next = NULL;
	return (token);
}

t_token	*string_process(t_lexer *lexer)
{
	char	*value;
	size_t	start;

	start = lexer->i;
	while (lexer->c != '\0')
	{
		if (lexer->c == ' ')
			break ;
		increment_using_index(lexer);
	}
	value = ft_substr(lexer->content, start, lexer->i - start);
	return (creat_token(value));
}


t_token	*tokenize(t_lexer *lexer)
{
	while (lexer->c != '\0' && lexer->i < ft_strlen(lexer->content))
	{
		if (lexer->c == ' ' || lexer->c == '\t' || lexer->c == '\n'
			|| lexer->c == '\r' || lexer->c == '\f' || lexer->c == '\v')
			while (lexer->c == ' ' || lexer->c == '\t' || lexer->c == '\n'
				|| lexer->c == '\r' || lexer->c == '\f' || lexer->c == '\v')
				increment_using_index(lexer);	
			return (string_process(lexer));	
	}
	return (creat_token("END"));
}


void	ft_lstadd_back_token(t_token **lst, t_token *new)
{
	t_token	*tmp;

	if (!lst || !new)
		return ;
	tmp = *lst;
	if (*lst)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
}

int ft_strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

void	print_linked_list(t_token *head_token)
{
	t_token *tmp = head_token;

	while (tmp)
	{
		printf("TOKEN VALUE ==> [%s] \n", tmp->value);
		tmp = tmp->next;
	}
	
}