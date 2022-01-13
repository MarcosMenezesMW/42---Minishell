/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:05:15 by mameneze          #+#    #+#             */
/*   Updated: 2021/12/04 22:13:28 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	checkenv(char *string)
{
	char	*fstquote;
	char	*lstquote;
	char	*txt;
	int		txtlen;

	lstquote = NULL;
	fstquote = ft_strchr(string, '"');
	if (fstquote != NULL)
		lstquote = ft_strchr((fstquote + 1), '"');
	if (lstquote != NULL)
	{
		txtlen = lstquote - fstquote;
		txt = malloc(txtlen);
		ft_strlcpy(txt, fstquote + 1, txtlen);
		printf("%s\n", txt);
	}
	if (!ft_strncmp(string, "PATH", 7))
		printf("%s\n", getenv(string));
	if (!ft_strncmp(string, "HOME", 7))
		printf("%s\n", getenv(string));
}

int main(void)
{
	char	*line;

	while(1)
	{
		line = readline("my-shell$ ");
		if (line != NULL)
			checkenv(line);
	}
	return (0);
}
