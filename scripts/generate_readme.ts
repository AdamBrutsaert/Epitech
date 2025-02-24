import Bun from "bun";

interface Project {
  name: string;
  madeWith: string[];
  percentage: number | "Build Error" | "Crash" | null;
  note: number | null;
}

interface Module {
  code: string;
  name: string;
  grade: "A" | "B" | "C" | "D" | "E" | "Acquired" | "Failed";
  projects: Project[];
}

interface Semester {
  number: number;
  modules: Module[];
}

interface AcademicYear {
  name: string;
  credits: number;
  gpa: number;
  tepitech: number;
  semesters: Semester[];
}

const academicYears: AcademicYear[] = [
  {
    name: "Tek 1",
    credits: 70,
    gpa: 3.94,
    tepitech: 815,
    semesters: [
      {
        number: 1,
        modules: [
          {
            code: "B-CPE-100",
            name: "B1 - Unix & C Lab Seminar (Part I)",
            grade: "A",
            projects: [
              {
                name: "C Pool Day 01",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "C Pool Day 02",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "C Pool Day 03",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "C Pool Day 04",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "C Pool Day 05",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "C Pool Day 06",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "C Pool Day 07",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "C Pool Day 08",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "C Pool Day 09",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "C Pool Day 10",
                madeWith: [],
                percentage: 83,
                note: 17,
              },
              {
                name: "C Pool Day 11",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "C Pool Day 12",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "C Pool Day 13",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "Rush 1",
                madeWith: ["Sonny Naidja"],
                percentage: 100,
                note: 22,
              },
              {
                name: "Rush 2",
                madeWith: ["Noah Beun"],
                percentage: 100,
                note: 20,
              },
              {
                name: "Star",
                madeWith: [],
                percentage: 100,
                note: 21,
              },
              {
                name: "Count Island",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "Lib Workshop",
                madeWith: [],
                percentage: 100,
                note: null,
              },
            ],
          },
          {
            code: "B-CPE-101",
            name: "B1 - Unix & C Lab Seminar (Part II)",
            grade: "A",
            projects: [
              {
                name: "Mini Printf",
                madeWith: [],
                percentage: 100,
                note: 26,
              },
              {
                name: "Printf",
                madeWith: ["Yanis Zeghiche"],
                percentage: 100,
                note: 21,
              },
              {
                name: "Final Stumper",
                madeWith: ["Sacha Polerowicz"],
                percentage: 31,
                note: 6,
              },
            ],
          },
          {
            name: "B1 - C Graphical Programming",
            code: "B-MUL-100",
            grade: "A",
            projects: [
              {
                name: "My Hunter",
                madeWith: [],
                percentage: "Build Error",
                note: 36,
              },
              {
                name: "My Radar",
                madeWith: [],
                percentage: 100,
                note: 57,
              },
            ],
          },
          {
            code: "B-MAT-100",
            name: "B1 - Mathematics",
            grade: "A",
            projects: [
              {
                name: "101pong",
                madeWith: ["Adam Cavillon"],
                percentage: 97,
                note: 19.8,
              },
              {
                name: "102architect",
                madeWith: ["Yanis Zeghiche"],
                percentage: 100,
                note: 20,
              },
              {
                name: "103cipher",
                madeWith: ["Yanis Zeghiche"],
                percentage: "Crash",
                note: 1.5,
              },
              {
                name: "104intersection",
                madeWith: ["Yanis Zeghiche"],
                percentage: 96,
                note: 19,
              },
              {
                name: "105torus",
                madeWith: ["Yanis Zeghiche"],
                percentage: 94,
                note: 19,
              },
            ],
          },
          {
            code: "B-CPE-110",
            name: "B1 - Elementary Programming in C",
            grade: "A",
            projects: [
              {
                name: "BSQ",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "Pushswap",
                madeWith: [],
                percentage: 89,
                note: 14.8,
              },
              {
                name: "Antman",
                madeWith: [],
                percentage: "Crash",
                note: 1.5,
              },
            ],
          },
          {
            code: "B-PSU-100",
            name: "B1 - Unix System Programming",
            grade: "A",
            projects: [
              {
                name: "MyLs",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "MySokoban",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "MyNavy",
                madeWith: ["Yanis Zeghiche"],
                percentage: 100,
                note: 20,
              },
            ],
          },
        ],
      },
      {
        number: 2,
        modules: [
          {
            code: "B-CPE-210",
            name: "B2 - Stumper",
            grade: "Acquired",
            projects: [
              {
                name: "Solo Stumper 1",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "Stumper 1",
                madeWith: ["Gianni Henriques"],
                percentage: 50,
                note: 9,
              },
              {
                name: "Stumper 2",
                madeWith: ["Gianni Henriques"],
                percentage: 100,
                note: 23,
              },
            ],
          },
          {
            code: "B-DOP-200",
            name: "B2 - Introduction to DevOps",
            grade: "A",
            projects: [
              {
                name: "Popeye",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "Chocolatine (VF: Petit pain)",
                madeWith: [],
                percentage: null,
                note: 37,
              },
            ],
          },
          {
            code: "B-MAT-200",
            name: "B2 - Mathematics",
            grade: "A",
            projects: [
              {
                name: "106bombyx",
                madeWith: ["Yanis Zeghiche"],
                percentage: 100,
                note: 20,
              },
              {
                name: "107transfer",
                madeWith: ["Yanis Zeghiche"],
                percentage: 64,
                note: 10.6,
              },
              {
                name: "108trigo",
                madeWith: ["Yanis Zeghiche"],
                percentage: 100,
                note: 20,
              },
              {
                name: "109titration",
                madeWith: ["Yanis Zeghiche"],
                percentage: 95,
                note: 19.9,
              },
              {
                name: "110borwein",
                madeWith: ["Yanis Zeghiche"],
                percentage: 100,
                note: 20,
              },
            ],
          },
          {
            code: "B-PSU-200",
            name: "B2 - Shell Programming",
            grade: "A",
            projects: [
              {
                name: "Minishell1",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "Minishell2",
                madeWith: [],
                percentage: 98,
                note: 37.4,
              },
              {
                name: "42sh",
                madeWith: ["Alexandre Barberis", "Adam Cavillon", "Yanis Zeghiche"],
                percentage: 74,
                note: 1.5,
              },
            ],
          },
          {
            code: "B-WEB-200",
            name: "B2 - Introduction to Web Development",
            grade: "A",
            projects: [
              {
                name: "EPyTodo",
                madeWith: ["Alexandre Barberis", "Thibault Longuepee"],
                percentage: null,
                note: 20,
              },
            ],
          },
          {
            code: "B-CPE-200",
            name: "B2 - Elementary Programming in C",
            grade: "A",
            projects: [
              {
                name: "Dante",
                madeWith: ["Yanis Zeghiche"],
                percentage: 81,
                note: 14,
              },
              {
                name: "Lem-in",
                madeWith: ["Anastasiia Romanova", "Romaric Loevenbruck", "Yanis Zeghiche"],
                percentage: 97,
                note: 21.7,
              },
              {
                name: "Corewar",
                madeWith: ["Alexandre Barberis", "Adam Cavillon", "Yanis Zeghiche"],
                percentage: 98,
                note: 12,
              },
            ],
          },
          {
            code: "B-MUL-200",
            name: "B2 - C Graphical Programming",
            grade: "B",
            projects: [
              {
                name: "MyPaint",
                madeWith: ["Yanis Zeghiche"],
                percentage: 100,
                note: 21,
              },
              {
                name: "MyRPG",
                madeWith: ["Alexandre Barberis", "Adam Cavillon", "Yanis Zeghiche"],
                percentage: 50,
                note: 1,
              },
            ],
          },
        ],
      },
    ],
  },
  {
    name: "Tek 2",
    credits: 63,
    gpa: 3.91,
    tepitech: 880,
    semesters: [
      {
        number: 3,
        modules: [
          {
            code: "B-PDG-300",
            name: "B3 - Paradigms Seminar",
            grade: "A",
            projects: [
              {
                name: "Day 01",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "Day 02",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "Day 03",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "Day 04 AM",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "Day 04 PM",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "Day 05",
                madeWith: [],
                percentage: 100,
                note: 19,
              },
              {
                name: "Day 06",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "Day 07 AM",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "Day 07 PM",
                madeWith: [],
                percentage: 80,
                note: 15,
              },
              {
                name: "Day 08",
                madeWith: [],
                percentage: 83.3,
                note: 15,
              },
              {
                name: "Day 09",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "Day 10",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "Day 11",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "Day 12",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "Day 13",
                madeWith: [],
                percentage: 100,
                note: 20,
              },
              {
                name: "Rush 1",
                madeWith: ["Yanis Zeghiche"],
                percentage: 100,
                note: 33,
              },
              {
                name: "Rush 2",
                madeWith: ["Alexandre Barberis", "Adam Cavillon", "Yanis Zeghiche"],
                percentage: 100,
                note: 34,
              },
              {
                name: "Rush 3",
                madeWith: ["Alexandre Barberis", "Adam Cavillon", "Yanis Zeghiche"],
                percentage: null,
                note: 17,
              },
            ],
          },
        ],
      },
      {
        number: 4,
        modules: [
          {
            code: "B-ASM-400",
            name: "B4 - x86-64 Assembly",
            grade: "A",
            projects: [
              {
                name: "MiniLibC",
                madeWith: [],
                percentage: 100,
                note: 25,
              },
            ],
          },
          {
            code: "B-DOP-400",
            name: "B4 - DevOps",
            grade: "A",
            projects: [
              {
                name: "MyMarvin",
                madeWith: ["Malo Durand"],
                percentage: 100,
                note: 20,
              },
              {
                name: "Octopus",
                madeWith: ["Malo Durand"],
                percentage: null,
                note: 41,
              },
            ],
          },
          {
            code: "B-NWP-400",
            name: "B4 - Network Programming",
            grade: "A",
            projects: [
              {
                name: "MyFTP",
                madeWith: [],
                percentage: 100,
                note: 19.8,
              },
              {
                name: "MyTeams",
                madeWith: ["Alexandre Barberis", "Merlin Cyffers"],
                percentage: 100,
                note: 16,
              },
            ],
          },
          {
            code: "B-OOP-400",
            name: "B4 - Object-Oriented Programming",
            grade: "A",
            projects: [
              {
                name: "NanoTekSpice",
                madeWith: ["Yanis Zeghiche"],
                percentage: 94,
                note: 17.08,
              },
              {
                name: "Arcade",
                madeWith: ["Yanis Zeghiche"],
                percentage: 100,
                note: 20.25,
              },
              {
                name: "RayTracer",
                madeWith: ["Alexandre Barberis", "Adam Cavillon", "Yanis Zeghiche"],
                percentage: null,
                note: 27.5,
              },
            ],
          },
          {
            code: "B-MAT-400",
            name: "B4 - Mathematics",
            grade: "A",
            projects: [
              {
                name: "201yams",
                madeWith: ["Yanis Zeghiche"],
                percentage: 100,
                note: 20,
              },
              {
                name: "202unsold",
                madeWith: ["Yanis Zeghiche"],
                percentage: 97.4,
                note: 19,
              },
              {
                name: "203hotline",
                madeWith: ["Yanis Zeghiche"],
                percentage: 100,
                note: 20,
              },
              {
                name: "204ducks",
                madeWith: ["Yanis Zeghiche"],
                percentage: 81.3,
                note: 14.5,
              },
              {
                name: "205IQ",
                madeWith: ["Adam Cavillon"],
                percentage: 95,
                note: 18,
              },
              {
                name: "206neutrinos",
                madeWith: ["Yanis Zeghiche"],
                percentage: 91.7,
                note: 18.7,
              },
              {
                name: "207demography",
                madeWith: ["Yanis Zeghiche"],
                percentage: 100,
                note: 20,
              },
              {
                name: "208dowels",
                madeWith: ["Yanis Zeghiche"],
                percentage: 100,
                note: 20,
              },
              {
                name: "209poll",
                madeWith: ["Yanis Zeghiche"],
                percentage: 96.2,
                note: 19.2,
              },
            ],
          },
          {
            code: "B-CCP-400",
            name: "B4 - Concurrent Programming",
            grade: "B",
            projects: [
              {
                name: "Panoramix",
                madeWith: [],
                percentage: 100,
                note: 15,
              },
              {
                name: "The Plazza",
                madeWith: ["Yanis Zeghiche"],
                percentage: "Build Error",
                note: 19,
              },
            ],
          },
          {
            code: "B-YEP-400",
            name: "B4 - Year-End-Project - Zappy",
            grade: "A",
            projects: [
              {
                name: "Zappy",
                madeWith: ["Alexandre Barberis", "Adam Cavillon", "Malo Durand", "Merlin Cyffers", "Yanis Zeghiche"],
                percentage: null,
                note: 51,
              },
            ],
          },
        ],
      },
    ],
  },
];

function getHeader(academicYears: AcademicYear[]) {
  let content = "# Epitech\n\n";

  content += "This repository showcases all the projects I completed during my studies at Epitech.  \n";
  content += "You're welcome to explore them for inspiration or to deepen your understanding of specific topics.\n\n";

  content += "> [!WARNING]\n";
  content += "> **Do not copy and paste** any code from this repository, as it constitutes academic dishonesty.\n\n";

  content += "## Academic Years\n\n";

  content += "<table>";
  content += "<thead>";
  content += "<tr>";
  content += "<th>Academic Year</th>";
  content += "<th>Credits</th>";
  content += "<th>GPA</th>";
  content += "<th>Tepitech</th>";
  content += "</tr>";
  content += "</thead>";
  content += "<tbody>";

  for (const academicYear of academicYears) {
    content += "<tr>";
    content += `<td>${academicYear.name}</td>`;
    content += `<td>${academicYear.credits}</td>`;
    content += `<td>${academicYear.gpa}</td>`;
    content += `<td>${academicYear.tepitech}</td>`;
    content += "</tr>";
  }

  content += "</tbody>";
  content += "</table>\n\n";

  return content;
}

function getSemester(semester: Semester) {
  let content = `### Semester ${semester.number}\n\n`;

  content += "<table>";
  content += "<thead>";
  content += "<tr>";
  content += '<th colspan="3">Module</th>';
  content += '<th colspan="4">Projects</th>';
  content += "</tr>";
  content += "<tr>";
  content += "<th>Code</th>";
  content += "<th>Name</th>";
  content += "<th>Grade</th>";
  content += "<th>Name</th>";
  content += "<th>Made With</th>";
  content += "<th>Percentage</th>";
  content += "<th>Note</th>";
  content += "</tr>";
  content += "</thead>";
  content += "<tbody>";

  for (const module of semester.modules) {
    content += "<tr>";
    content += `<td rowspan="${module.projects.length + 1}">${module.code}</td>`;
    content += `<td rowspan="${module.projects.length + 1}">${module.name}</td>`;
    content += `<td rowspan="${module.projects.length + 1}">${module.grade}</td>`;
    content += "</tr>";

    for (const project of module.projects) {
      content += "<tr>";
      content += `<td>${project.name}</td>`;
      content += `<td>${project.madeWith.join(", ")}</td>`;
      content += `<td>${project.percentage ?? ""}</td>`;
      content += `<td>${project.note ?? ""}</td>`;
      content += "</tr>";
    }
  }

  content += "</tbody>";
  content += "</table>\n";

  return content;
}

function getReadMe() {
  let content = getHeader(academicYears);
  content += academicYears.map((a) => a.semesters.map((s) => getSemester(s)).join("\n")).join("\n");
  return content;
}

Bun.write("README.md", getReadMe());
