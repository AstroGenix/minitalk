/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:39:51 by dberehov          #+#    #+#             */
/*   Updated: 2023/05/20 15:39:53 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1.Start the server:
	The server should be started first.
	Upon launch, it needs to print its Process ID (PID) to uniquely identify itself.
	In most programming languages, you can obtain the PID using built-in functions or libraries specific to that language.

2.Signal Handling:
	The server needs to set up signal handlers to handle the signals sent by the clients.
	In this case, we will handle the SIGUSR1 and SIGUSR2 signals.
	When a signal is received, the server needs to perform specific actions based on the signal received.

3.Receive and Process Strings:
	The server needs to receive strings from clients.
	When a client sends a signal (e.g., SIGUSR1) to the server, it indicates that a string is being sent.
	The server needs to capture and process the incoming string.

4.Print the Received String:
	Once the server receives the string, it needs to print it.
	It is essential to ensure that the server can display the string pretty quickly, as specified in the exercise.
	The exact method for printing will depend on the programming language you choose.

5.Loop and Wait for Signals:
	After printing the received string, the server should continue to listen for signals from clients.
	It should be capable of receiving strings from multiple clients in a row without needing a restart.
	The server should be in a loop, waiting for signals to arrive.
*/
