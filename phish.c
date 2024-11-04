#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_QUESTIONS 15
#define NUM_OPTIONS 4

typedef struct {
    char question[256];
    char options[NUM_OPTIONS][128];
    char correct_option;
    char explanations[NUM_OPTIONS][256];
} QuizQuestion;

// Helper function to initialize a single question so that we dont have to be 
// repetitive.
void set_question(QuizQuestion *q, const char *question, const char *options[],
                  char correct_option, const char *explanations[]) {
    strncpy(q->question, question, sizeof(q->question) - 1);
    for (int i = 0; i < NUM_OPTIONS; i++) {
        strncpy(q->options[i], options[i], sizeof(q->options[i]) - 1);
        strncpy(q->explanations[i], explanations[i], sizeof(q->explanations[i]) - 1);
    }
    q->correct_option = toupper(correct_option);
}

// Initializing the questions.
void initialize_quiz(QuizQuestion quiz[]) {
    const char *optionsOne[] = {
        "A. Reply with your zid and password\n.",
        "B. Just ignore the text message\n",
        "C. Click the link provided in the messages\n.",
        "D. Call the university using the number in the text message.\n"
    };
    const char *explanationsOne[] = {
        "Authentic schools will not ask for your uni details via text. :(\n",
        "Ignoring text requesting personal information is the safest thing to do. :)\n",
        "Links in untrusted messages can proceed to taking you to phishing websites. :(\n",
        "Please always call the university using the correct contact details issued in your official school website not in random text messages. :(\n"
    };
    set_question(&quiz[0], "You receive a text from your university asking for your zID and password. What actions will you take?\n", optionsOne, 'B', explanationsOne);

    const char *optionsTwo[] = {
        "A. Give them your information so that you stand a chance to win\n",
        "B. Click x and close the pop up message\n",
        "C. Tap on the link to try and understand what the offer is all about\n",
        "D. Show this to your family and friends so that they stand a chance too.\n"
    };
    const char *explanationsTwo[] = {
        "Sharing your personal information to a random pop-up could lead to theft. :(\n",
        "Taping x in this scenerio would be the best approach, good job!:)\n",
        "Taping links could result to malware being installed on your device:(\n",
        "Showing this to other people may lead to the attack spreading, dont do it!!:(\n"
    };
    set_question(&quiz[1], "A message pops up on your movie site that you have won 10M$ , what is your next step\n?", optionsTwo, 'B', explanationsTwo);

    const char *optionsThree[] = {
        "A. Be curious and check what is inside",
        "B. Give Jade a call and ask him if he sent a link",
        "C. Ghost Jade",
        "D. Share this link with your friends on a friends groupchat"
    };
    const char *explanationsThree[] = {
        "Taping links could result to malware being installed on your device :(\n",
        "Giving Jade a call would be the best option to confirm if it is authentic or not :)\n",
        "You need to report that to the necessary channel so that it doesn't happen again:(\n",
        "Forwarding suspicious links can spread potential threats. :(\n"
    };
    set_question(&quiz[2], "Your friend Jade has sent a weird link on your instagram, what do you do?\n", optionsThree, 'B', explanationsThree);
    const char *optionsFour[] = {
        "A. Open the document to read the payslip\n",
        "B. Reply to the email to ask for the next steps\n",
        "C. Get rid of the email without checking what's inside the document\n",
        "D. Send this email to your coworkers\n"
    };
    const char *explanationsFour[] = {
        "Accessing thr document can lead to the introduction of malware:(\n",
        "Do not talk or have a converstaion with an unknown sender:(\n",
        "Getting rid of the email would be the safest approach\n:)",
        "This could lead to the potential spread of a threat\n. :("
    };
    set_question(&quiz[3], "You receive an email from someone you dont know that says 'Payslip'. What will you do?\n", optionsFour, 'C', explanationsFour);

    const char *optionsFive[] = {
        "A. The site is secure and encrypted.\n",
        "B. The site is not secure and data is transmitted in plain text.\n",
        "C. The site is a phishing site.\n",
        "D. The site is a government website.\n"
    };
    const char *explanationsFive[] = {
        "with 'http' - that site has no encryption:(",
        "with 'http' means that the data on there is not encrypted making it vulnerable\n:)",
        "it doesn't mean that it is phishing site but it not having encryption is not a really good thing:(\n",
        "it starting with http does not show what the site is associated with:(\n"
    };
    set_question(&quiz[4], "You encounter a website that starts with 'http:// and not https: This means?\n", optionsFive, 'B', explanationsFive);

    

    const char *optionsSix[] = {
        "A. Give them permission to help fix the problem\n",
        "B. Ask them for their employment no and for them to call you again\n",
        "C. Get off the phone with them and try contacting the company directly using the correct contact details\n",
        "D. Be curious and get to know who you are talking to\n"
    };
    const char *explanationsSix[] = {
        "Giving them permission can cause unnecessary issues to your device:(\n",
        "Attackers can guess a random employment number with ease:(\n",
        "Calling the company directly would be safer to make sure you are speaking with the correct individuals:)\n",
        "Talking with attackers would put you in avulnerable position for potential exploit:(\n"
    };
    set_question(&quiz[5], "You get a call from someone accessing for access to\n your device saying they are 'tech support' what would your response be?\n", optionsSix, 'C', explanationsSix);

    const char *optionsSeven[] = {
        "A. Tap the link in the message to confirm\n",
        "B. Just ignore that text\n",
        "C. Give a call to the company correct contact details\n",
        "D. Do what the message is asking you to\n."
    };
    const char *explanationsSeven[] = {
        "Do not tap, you may be exposed to a phishing attack:(\n",
        "Do not ignore cause it may cause serious problems:(\n",
        "Giving the company a call would be a safer choice :)\n",
        "Doing what the message tells you is a dangerous step as it may be phishing:(\n"
    };
    set_question(&quiz[6], "You get a text message saying your account will be closed if you dont act on that message, What will you do?\n", optionsSeven, 'C', explanationsSeven);

    const char *optionsEight[] = {
        "A. Tap on the link to see what is going on\n",
        "B. Visit cole's offical website to see what is going on\n",
        "C. Use the contacts provided to check if everything is ok\n",
        "D. Share the email with coles' contact support team\n"
    };
    const char *explanationsEight[] = {
        "Tapping on such emails may expose to a phishing attack:(\n",
        "Visiting the official website would be safest option. :)\n",
        "The contact details may be a trap. :(\n",
        "Sharing the email may lead to the spread of a phishing attack:(\n"
    };
    set_question(&quiz[7], "You receive an email from Coles claiming that there is a sus activity going on on your account. What will you do next?\n", optionsEight, 'B', explanationsEight);

    const char *optionsNine[] = {
        "A. Say yes to the offer asap\n",
        "B. Do research on the university\n",
        "C. Send your name and date of birth as requested\n",
        "D. Dont do anything, just ignore the email.\n"
    };
    const char *explanationsNine[] = {
        "Saying yes to offers withiut verification if not safe:(\n",
        "Doing research will help you check if the offer is legit:)\n",
        "Handing out your personal information may lead to the theft. :(\n",
        "Ignoring that may be safe but confirming if the offer is legit is safer.:(\n"
    };
    set_question(&quiz[8], "You get an offer from a university that you did not apply to, what will you do?\n", optionsNine, 'B', explanationsNine);

    const char *optionsTen[] = {
        "A. Go ahead and tap the link to change password\n.",
        "B. Search for the official apple web and change password from there\n",
        "C. Share this with your uncle in IT\n",
        "D. Dont do anything\n"
    };
    const char *explanationsTen[] = {
        "Tapping can lead you to a phishing site:(\n",
        "Changing the password from the officla website is the safest option:)\n",
        "Sharing may lead to them being threatened as well:(\n",
        "Ignoring the problem is not addresing the problem at hand and it may impact your security:(\n"
    };
    set_question(&quiz[9], "You get an email from 'Apple' that you need to change your passowrd, what will you do?\n", optionsTen, 'B', explanationsTen);

    const char *optionsEleven[] = {
        "A. Check what the attachment contains.",
        "B. Email your friend back to ask if everything is okay",
        "C. Get rid of the email",
        "D. Share the email with others"
    };
    const char *explanationsEleven[] = {
        "Checking what the attachment contains may introduce malware:(\n",
        "It may not be your friend you are talking maybe it is a scammer, \n not a safe option!!:(\n",
        "Getting rid of the email may be a good option in this case:)\n",
        "Sharing may lead to them being threatened potentially:(\n"
    };
    set_question(&quiz[10], "You just got an email from your friend that has a weird subject message but has no body text in it, what do you do in this situation?\n", optionsEleven, 'C', explanationsEleven);

    const char *optionsTwelve[] = {
        "A. Tap on the link to confirm\n",
        "B. Report the post\n",
        "C. Share the post on your page and to your friends\n.",
        "D. Respond on the comment section to ask for a link.\n"
    };
    const char *explanationsTwelve[] = {
        "Tapping on the link may introduce phishing attacks or malware :(\n",
        "Reporting the post would be the appropriate thing to do. :)\n",
        "Sharing would lead to potential threats to other people:(\n",
        "Responding and engaging may lead to you giving out your personal information:(\n"
    };
    set_question(&quiz[11], "A post on FaceBook reads that a famous person is dead and you should click a certain link:\n what steps will you take?\n", optionsTwelve, 'B', explanationsTwelve);

    const char *optionsThirteen[] = {
        "A. Reply saying that you are ubale to understand the language\n",
        "B. Ignore or delete the email.\n",
        "C. Send money as you are required.\n",
        "D. Forward it to your friends and family.\n"
    };
    const char *explanationsThirteen[] = {
        "Replying may lead to more attacks. :(\n",
        "Ignoring or deleting the email is the safest option. :)\n",
        "Sending money without verifying would be risky:(\n",
        "Forwarding the email may lead to potential threats on them too :(\n"
    };
    set_question(&quiz[12], "An email is sent to you written that you send money and it is in another language, what will you do?\n", optionsThirteen, 'B', explanationsThirteen);

    const char *optionsFourteen[] = {
        "A. Accept the friend request and follow them.\n",
        "B. Cancelling the request\n",
        "C. DM them and ask them for information\n",
        "D. check out their page and stalk them\n"
    };
    const char *explanationsFourteen[] = {
        "Dont accept as it may lead to your info being exposed. :(\n",
        "Cancelling the request would be a great option. :)",
        "Messaging them can put you in a potential phishing attack situation. :(\n",
        "Checking out profiles can show data to the attacker. :(\n"
    };
    set_question(&quiz[13], "You have gotten a friend req from facebook from a person you dont know,  What should you do?\n", optionsFourteen, 'B', explanationsFourteen);

    const char *options15[] = {
        "A. Go ahead and open the file\n",
        "B. Get rid of the file\n",
        "C. Delete the software and unsubscribe\n",
        "D. Forward the file to a friend.\n"
    };
    const char *explanations15[] = {
        "This may expose you to viruses and bugs:(\n",
        "Getting rid of the file would be the safest option :)\n",
        "You wont be protecting your device if you delete the software :(\n",
        "Sharing can lead to potential threat :(\n"
    };
    set_question(&quiz[14], "A software that alerts you for malware send you a warning. What should you do?\n", options15, 'B', explanations15);
}

// Function that helps to conduct the quiz
void conduct_quiz(QuizQuestion quiz[], int num_questions) {
    char answer;
    int score = 0;

    for (int i = 0; i < num_questions; i++) {
        int correct = 0;
        while (!correct) {
            printf("%s\n", quiz[i].question);
            for (int j = 0; j < NUM_OPTIONS; j++) {
                printf("%s\n", quiz[i].options[j]);
            }
            printf("Your answer (A/B/C/D): ");
            scanf(" %c", &answer);
            answer = toupper(answer);

            if (answer == quiz[i].correct_option) {
                printf("Correct! %s\n\n", quiz[i].explanations[answer - 'A']);
                score++;
                correct = 1;
            } else {
                printf("Incorrect. %s\n\n", quiz[i].explanations[answer - 'A']);
                printf("Please try again.\n\n");
            }
        }
        printf("\n");
    }

    printf("Your final score: %d out of %d\n", score, num_questions);
}

int main() {
    QuizQuestion quiz[NUM_QUESTIONS];
    initialize_quiz(quiz);
    conduct_quiz(quiz, NUM_QUESTIONS);
    return 0;
}
