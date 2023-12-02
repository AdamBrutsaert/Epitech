/*
** EPITECH PROJECT, 2023
** network_initialize.c
** File description:
** network_initialize.c
*/

#include "buffer.h"
#include "network.h"

#include <signal.h>
#include <stddef.h>

static void on_user_signal(int nb, siginfo_t *info,
    __attribute__((unused)) void *ctx)
{
    pid_t peer;
    bit_t bit = nb == SIGUSR1 ? BIT_0 : BIT_1;

    network_peer(GET, &peer);
    if (peer == -1) {
        peer = info->si_pid;
        network_peer(SET, &peer);
    }
    if (peer != info->si_pid)
        return;
    network_buffer(PUSH, &bit);
}

void network_initialize(void)
{
    struct sigaction action;

    network_buffer(CREATE, NULL);
    action.sa_flags = SA_SIGINFO;
    sigemptyset(&action.sa_mask);
    action.sa_sigaction = &on_user_signal;
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
}
