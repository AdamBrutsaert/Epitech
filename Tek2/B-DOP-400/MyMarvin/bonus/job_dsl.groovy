folder("Bonus") {
    description("Folder for bonus tools.")
    displayName("Bonus")
}

freeStyleJob("Bonus/SEED") {
    parameters {
        stringParam("GITHUB_NAME", null, "GitHub repository owner/repo_name (e.g.: \"EpitechIT31000/chocolatine\")")
        stringParam("DISPLAY_NAME", null, "Display name for the job")
        stringParam("RECIPIENT_LIST", null, "Student emails list to send build log to (comma separated)")
    }
    steps {
        dsl {
            text("""
freeStyleJob("\$DISPLAY_NAME") {
    displayName("\$DISPLAY_NAME")
    scm {
        git {
            remote {
                github("\$GITHUB_NAME", "https")
                credentials("git-credentials")
            }
            branch("*/main")
        }
        triggers {
            // TA Delay here (each 1 minute for now)
            pollSCM {
                scmpoll_spec('* * * * *')
                ignorePostCommitHooks(false)
            }
        }
    }
    wrappers {
        preBuildCleanup {
            preBuildCleanup()
        }
        buildInDocker {
            image('epitechcontent/epitest-docker:latest')
            verbose()
        }
    }
    steps {
        shell("make fclean")
        shell("make")
        shell("make tests_run")
        shell("make clean")
    }
    publishers {
        extendedEmail {
            triggers {
                always {
                    attachBuildLog(true)
                    defaultContent("See attached file for details.")
                    recipientList("\$RECIPIENT_LIST")
                }
            }
        }
    }
}
    """)
        }
    }
}
