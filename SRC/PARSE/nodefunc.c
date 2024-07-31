#include "../../INC/cub3d.h"

void del_map_node_from_head(t_game *game)
{
    t_map *tmp;
    t_map *next_node;

    tmp = game->map_head;
    while (tmp)
    {
        next_node = tmp->next;

        if (same_str(tmp->line, "\n") || ft_is_all_space(tmp->line))
        {
            if (tmp->prev)
                tmp->prev->next = tmp->next;
            else
                game->map_head = tmp->next;

            if (tmp->next)
                tmp->next->prev = tmp->prev;
            else
                game->map_tail = tmp->prev;
            free(tmp->line);
            free(tmp);
        }
		else
			break;
        tmp = next_node;
    }
}

void del_map_node_from_tail(t_game *game)
{
    t_map *tmp;
    t_map *prev_node;

    tmp = game->map_tail;
    while (tmp)
    {
        prev_node = tmp->prev;
        if (same_str(tmp->line, "\n") || ft_is_all_space(tmp->line))
        {
            if (tmp->prev) 
                tmp->prev->next = tmp->next;
            else 
                game->map_head = tmp->next;
            if (tmp->next) 
                tmp->next->prev = tmp->prev;
            else 
                game->map_tail = tmp->prev;
            free(tmp->line);
            free(tmp);
        }
        else
            break;
        tmp = prev_node;
    }
}




void add_map_node(t_game *game, char *line)
{
    t_map *new_node;
    t_map *tmp;

    new_node = ft_calloc(sizeof(t_map), 1);
    if (!new_node)
    {
        ft_error("Malloc doesn't work!");
        return;
	}
    new_node->line = ft_strdup(line);
    if (!new_node->line)
    {
        free(new_node);
        ft_error("Malloc doesn't work!");
        return;
	}
    if (!game->map_head)
    {
        game->map_head = new_node;
        game->map_tail = new_node;
    }
    else
    {
        tmp = game->map_tail;
        if (tmp)
        {
            tmp->next = new_node;
            new_node->prev = tmp;
            game->map_tail = new_node;
        }
        else
        {
            free(new_node->line);
            free(new_node);
            ft_error("Corrupted map_tail!");
        }
    }
}