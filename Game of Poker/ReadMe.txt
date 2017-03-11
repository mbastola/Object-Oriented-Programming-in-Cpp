#Five Cards Draw
Rules:
Before each round an ante of one chip is deducted from each player's chip count and added to a common pot of chips that will go to the winner of the round.

During each of two betting phases in each round (one phase before cards are drawn and one after cards are drawn) the program rotates among the remaining players, prompts each player for which action to take (and how many chips to bet or raise for those actions), deducts the chips each player bets, calls, or raises from their chip total, and records the cumulative amount they have bet during that phase 

During a phase, if no other player has bet so far, the next player may either check (staying in the round but not risking any more chips at that point) or bet either 1 or 2 chips.

Once a player does bet during a phase, then the other players must either fold (dropping out of the round and having their chips bet so far in that round pushed into the pot), call all previous bets and raises that they have not called (by increasing their cumulative number of chips bet to match the highest cumulative bet of any other player in the phase so far), or raise 1 or 2 chips in addition to the amount needed to call any earlier bet or raise.

If a player runs out of chips during a phase, they will remain in the round with no further obligation to call, bet, or raise in that phase (or any subsequent phase) until the round is over. For simplicity they will be able to win the entire pot (or a split of it in the case of a tie) if their hand is highest (if you would like to do so you may instead choose to implement support for side pots, though it is not required to do so).

If all players check and no-one bets the phase simply ends without any chips being added to the pot. If someone does bet the phase continues until the most recent bet or raise has been called by all remaining players or until all but one player has folded. At the end of the phase all chips bet (including those by players who later folded) are pushed into the pot.

If all players except one decide to fold, then the entire pot is awarded to the remaining player, their win count is increased by one, and the round ends.

Otherwise after the last betting phase of a round the hands of the players that remain are ranked, the pot is added to the chip count of the player with the highest hand (or is split among the players having identically highest hands if there are ties at the top), and the winning player(s) win count is increased by one and the other remaing players loss counts are increased by one.

*At the end of each round the game prints out each player's name, wins, losses, and chip counts, and either their hands if they stayed in until the end of the round or an indication that they folded without showing down their hand.

*If the user chooses to play a new game the program prompts for the name of the game and the names of the players (re-prompting for whether to quit or play again etc. as needed if an invalid game name is given).
