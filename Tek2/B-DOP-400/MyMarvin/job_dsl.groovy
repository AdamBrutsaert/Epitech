folder("Tools") {
    description("Folder for miscellaneous tools.")
    displayName("Tools")
}

freeStyleJob("Tools/clone-repository") {
    parameters {
        stringParam("GIT_REPOSITORY_URL", null, "Git URL of the repository to clone")
    }
    steps {
        shell("git clone \$GIT_REPOSITORY_URL")
    }
    wrappers {
        preBuildCleanup {
            preBuildCleanup()
        }
    }
}

freeStyleJob("Tools/SEED") {
    parameters {
        stringParam("GITHUB_NAME", null, "GitHub repository owner/repo_name (e.g.: \"EpitechIT31000/chocolatine\")")
        stringParam("DISPLAY_NAME", null, "Display name for the job")
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
            }
            branch("*/main")
        }
    }
    triggers {
        // TA Delay here (each 1 minute for now)
        pollSCM {
            scmpoll_spec('* * * * *')
            ignorePostCommitHooks(false)
        }
    }
    wrappers {
        preBuildCleanup {
            preBuildCleanup()
        }
    }
    steps {
        shell("make fclean")
        shell("make")
        shell("make tests_run")
        shell("make clean")
    }
}
    """)
        }
    }
}
