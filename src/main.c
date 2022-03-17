/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:10:09 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/17 14:50:59 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"
#include "utils/stringbuilder/stringbuilder.h"

void	test()
{
	char			*str;
	t_stringbuilder	builder;

	stringbuilder_create(&builder);
	stringbuilder_append_char(&builder, 'h');
	stringbuilder_append_char(&builder, 'a');
	stringbuilder_append_str(&builder, "llo welt!");
	str = stringbuilder_finalize(&builder);
	stringbuilder_destroy(&builder);
	printf("Result is: %s\n", str);
	free(str);
}

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	printf("This is cub3d!\n");
	test();
	return (0);
}
