/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:45:54 by dberehov          #+#    #+#             */
/*   Updated: 2023/05/20 14:45:56 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1.Server Initialization:
	We begin by starting the server first. Once launched, it needs to print its Process ID (PID) to uniquely identify itself.

2.Client Parameters:
	The client application requires two parameters:
	a. Server PID: This PID is necessary to establish a connection with the server.
	b. String to Send: The client needs to receive the string that will be sent to the server.

3.String Transmission:
	The client's main task is to send the string received as a parameter to the server.
	It achieves this by utilizing UNIX signals for communication.
	Signals are a way for processes in UNIX systems to send notifications to each other.

4.Server String Reception:
	Upon receiving the string from the client, the server needs to print it.
	The server should accomplish this task quickly.
	Keep in mind that the exercise suggests that taking 1 second to display 100 characters is too much, so we need to optimize the display speed.

5.Handling Multiple Clients:
	Our server should be able to handle strings from multiple clients in a row without requiring a restart.
	This implies that the server needs to be capable of receiving signals and processing strings from different clients sequentially.

6.Available Signals:
	The exercise restricts us to using only two signals: SIGUSR1 and SIGUSR2.
	SIGUSR1 and SIGUSR2 are user-defined signals, commonly used for inter-process communication in UNIX systems.
*/

