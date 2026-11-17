const INITIAL_STUDENTS = [
    { id: 1, name: "Sarah Jenkins", avatar: "👩🏻‍💻", role: "Web Development", offering: ["React", "JavaScript", "HTML/CSS"], learning: ["UI/UX Design", "Spanish"], bio: "Computer Science senior passionate about frontend frameworks and web accessibility.", rating: 4.9, reviews: 18, location: "Campus East" },
    { id: 2, name: "Ahmed Raza", avatar: "👨🏻‍🎨", role: "Graphic Design", offering: ["Figma", "Photoshop", "Branding"], learning: ["Python", "Digital Marketing"], bio: "Visual designer crafting intuitive interfaces and brand identities.", rating: 4.8, reviews: 24, location: "Design Studio A" },
    { id: 3, name: "Ayesha Malik", avatar: "👩🏻‍🎤", role: "Photography", offering: ["Portrait Photography", "Lightroom", "Color Grading"], learning: ["Video Editing", "French"], bio: "Freelance photographer focusing on natural light portraiture and color chemistry.", rating: 5.0, reviews: 31, location: "Media Center" },
    { id: 4, name: "Ali Khan", avatar: "👨🏻‍💻", role: "Programming", offering: ["C++", "Python", "Data Structures"], learning: ["Graphic Design", "Public Speaking"], bio: "Software engineering enthusiast focused on algorithms, competitive coding, and AI.", rating: 4.7, reviews: 15, location: "Tech Hub" },
    { id: 5, name: "Elena Rostova", avatar: "👩🏼‍💼", role: "Languages", offering: ["Spanish Native", "Russian", "Grammar"], learning: ["React", "Data Science"], bio: "Linguistics student eager to exchange language practice for tech skill mentoring.", rating: 4.9, reviews: 22, location: "Humanities Hall" },
    { id: 6, name: "Marcus Vance", avatar: "👨🏽‍🎵", role: "Music & Audio", offering: ["Guitar", "Ableton Live", "Audio Mixing"], learning: ["C++", "Web Development"], bio: "Audio engineer and guitarist sharing music production secrets for web dev skills.", rating: 4.9, reviews: 27, location: "Music Annex" }
];
const CATEGORIES = [
    ["all", "✨", "All Skills"],
    ["prog", "⌘", "Programming"],
    ["design", "🎨", "Graphic Design"],
    ["marketing", "📢", "Digital Marketing"],
    ["lang", "🌐", "Languages"],
    ["photo", "📷", "Photography"],
    ["music", "🎵", "Music & Audio"],
    ["uiux", "▣", "UI/UX Design"],
    ["data", "▦", "Data Science"]
];
let students = JSON.parse(localStorage.getItem("skillswapStudents") || "null") || INITIAL_STUDENTS;
let selectedCategory = "all", searchQuery = "", selectedStudent = null;
const getUser = () => JSON.parse(localStorage.getItem("skillswapUser") || "null");
const saveStudents = () => localStorage.setItem("skillswapStudents", JSON.stringify(students));
function notify(message, type = "success")
{
    const box = document.getElementById("toastBox");
    if (!box)
        return;
    box.textContent = message;
    box.className = "toast-message " + (type === "error" ? "error" : "");
    setTimeout(() => box.classList.add("d-none"), 3500);
    box.classList.remove("d-none");
}
function updateNav()
{
    const user = getUser(), actions = document.getElementById("navActions"), strip = document.getElementById("welcomeStrip");
    if (!actions)
        return;
    if (user)
    {
        actions.innerHTML = `<button class="btn btn-signup" data-bs-toggle="modal" data-bs-target="#postSkillModal">＋ Post Skill</button><span class="text-white small">${user.avatar || "🎓"} ${user.name}</span><button class="btn btn-login" id="logoutButton">Logout</button>`;
        strip.classList.remove("d-none");
        document.getElementById("welcomeName").textContent = user.name;
        document.getElementById("offeringCount").textContent = `Offering: ${(user.offering || []).length} Skills`;
        document.getElementById("learningCount").textContent = `Learning: ${(user.learning || []).length} Skills`;
        document.getElementById("joinButton").textContent = "Offer a Skill"; document.getElementById("joinButton").href = "#";
        document.getElementById("joinButton").onclick = e => {
            e.preventDefault();
            bootstrap.Modal.getOrCreateInstance(document.getElementById("postSkillModal")).show()
        };
        document.getElementById("logoutButton").onclick = () =>
        {
            localStorage.removeItem("skillswapUser");
            location.reload()
        };
    }
    else
    {
        actions.innerHTML = '<a class="btn btn-login" href="/Identity/Account/Login">Login</a><a class="btn btn-signup" href="/Identity/Account/Register">Sign Up</a>';
        strip.classList.add("d-none");
    }
}
function renderCategories()
{
    const wrap = document.getElementById("categoryFilters");
    if (!wrap)
        return;
    wrap.innerHTML = CATEGORIES.map(c => `<button class="filter-pill ${selectedCategory === c[0] ? "active" : ""}" data-category="${c[0]}">${c[1]} ${c[2]}</button>`).join("");
    wrap.querySelectorAll("button").forEach(b => b.onclick = () => {
        selectedCategory = b.dataset.category;
        renderCategories(); renderStudents()
    });
}
function categoryMatch(s)
{
    if (selectedCategory === "all")
        return true;
    const role = s.role.toLowerCase();
    const map = { prog: ["programming", "web"], design: ["design"], marketing: ["marketing"], lang: ["languages"], photo: ["photography"], music: ["music"], uiux: ["ui/ux", "design"], data: ["data"] };
    return (map[selectedCategory] || []).some(v => role.includes(v));
}
function renderStudents()
{
    const grid = document.getElementById("studentGrid");
    if (!grid)
        return;
    const q = searchQuery.toLowerCase();
    const list = students.filter(s => categoryMatch(s) && (!q || [s.name, s.role, ...s.offering, ...s.learning].some(v => v.toLowerCase().includes(q))));
    document.getElementById("studentCount").textContent = `Showing ${list.length} Students`;
    document.getElementById("noResults").classList.toggle("d-none", list.length !== 0);
    grid.innerHTML = list.map(s => `<div class="col-md-6 col-lg-4"><article class="student-card"><div><div class="student-top"><div class="student-person"><div class="student-avatar">${s.avatar}</div><div><h3 class="student-name">${s.name}</h3><div class="student-role">${s.role}</div><div class="student-location">${s.location}</div></div></div><span class="rating">★ ${s.rating}</span></div><p class="student-bio">${s.bio}</p><div class="skill-label">Teaches</div><div>${s.offering.map(x => `<span class="skill-chip">${x}</span>`).join("")}</div><div class="skill-label">Wants to learn</div><div>${s.learning.map(x => `<span class="skill-chip learning">${x}</span>`).join("")}</div></div><div class="student-actions"><button class="view-btn" data-profile="${s.id}">View Profile</button><button class="swap-btn" data-swap="${s.id}">Swap Skill</button></div></article></div>`).join("");
    grid.querySelectorAll("[data-profile]").forEach(b => b.onclick = () => showProfile(Number(b.dataset.profile)));
    grid.querySelectorAll("[data-swap]").forEach(b => b.onclick = () => openSwap(Number(b.dataset.swap)));
}
function showProfile(id)
{
    selectedStudent = students.find(s => s.id === id);
    const s = selectedStudent; document.getElementById("profileContent").innerHTML = `<div class="student-avatar mx-auto mb-3" style="width:78px;height:78px;font-size:42px">${s.avatar}</div><h3 class="fw-bold" style="color:var(--dark-purple)">${s.name}</h3><p class="text-purple small fw-bold">${s.role}</p><p class="text-secondary small">${s.location}</p><div class="text-start bg-light rounded-3 p-3 my-3"><strong class="small">About Me</strong><p class="small text-secondary mb-0 mt-1">${s.bio}</p></div><div class="text-start"><strong class="small">Skills Offered</strong><p>${s.offering.map(x => `<span class="skill-chip">${x}</span>`).join("")}</p><strong class="small">Wants to Learn</strong><p>${s.learning.map(x => `<span class="skill-chip learning">${x}</span>`).join("")}</p></div><button class="btn btn-main w-100" id="profileSwap">Request Swap</button>`;
    bootstrap.Modal.getOrCreateInstance(document.getElementById("profileModal")).show();
    document.getElementById("profileSwap").onclick = () =>
    {
        bootstrap.Modal.getOrCreateInstance(document.getElementById("profileModal")).hide();
        openSwap(id)
    };
}
function openSwap(id)
{
    if (!getUser())
    {
        location.href = "/Identity/Account/Login";
        return;
    }
    selectedStudent = students.find(s => s.id === id);
    document.getElementById("swapStudentName").textContent = `Propose an exchange with ${selectedStudent.name}`;
    const user = getUser();
    document.getElementById("teachSelect").innerHTML = (user.offering || []).map(x => `<option>${x}</option>`).join("") + '<option>Other custom topic...</option>';
    document.getElementById("learnSelect").innerHTML = selectedStudent.offering.map(x => `<option>${x}</option>`).join("");
    bootstrap.Modal.getOrCreateInstance(document.getElementById("swapModal")).show();
}
document.addEventListener("DOMContentLoaded", () =>
{
    updateNav();
    renderCategories();
    renderStudents();
    const input = document.getElementById("searchInput");
    if (input)
    {
        input.oninput = () =>
        {
            searchQuery = input.value;
            document.getElementById("clearSearch").classList.toggle("d-none", !searchQuery);
            renderStudents()
        };
        document.getElementById("clearSearch").onclick = () =>
        {
            input.value = ""; searchQuery = "";
            document.getElementById("clearSearch").classList.add("d-none");
            renderStudents()
        };
        document.getElementById("searchButton").onclick = () => document.getElementById("students").scrollIntoView({ behavior: "smooth" });
        document.getElementById("resetFilters").onclick = () =>
        {
            input.value = "";
            searchQuery = "";
            selectedCategory = "all";
            renderCategories();
            renderStudents()
        };
    }
    const post = document.getElementById("postSkillForm");
    if (post)
        post.onsubmit = e =>
        {
            e.preventDefault();
            const user = getUser();
            if (!user)
            {
                location.href = "/Identity/Account/Login";
                return;
            }
            const title = document.getElementById("skillTitle").value.trim(), type = document.querySelector('input[name="listingType"]:checked').value, category = document.getElementById("skillCategory").value, description = document.getElementById("skillDescription").value.trim(); if (!title || !description) return; user[type === "offering" ? "offering" : "learning"].push(title); localStorage.setItem("skillswapUser", JSON.stringify(user)); const idx = students.findIndex(s => s.name === user.name);
            if (idx >= 0)
                students[idx][type].push(title);
            else
                students.unshift({ id: Date.now(), name: user.name, avatar: user.avatar || "🎓", role: category, offering: type === "offering" ? [title] : ["Peer Mentoring"], learning: type === "learning" ? [title] : ["General Skills"], bio: description, rating: 5, reviews: 1, location: "Online / Campus" }); saveStudents(); bootstrap.Modal.getInstance(document.getElementById("postSkillModal")).hide(); post.reset(); updateNav(); renderStudents(); notify(`Skill "${title}" published!`);
        };
    const swap = document.getElementById("swapForm");
    if (swap) swap.onsubmit = e =>
    {
        e.preventDefault();
        bootstrap.Modal.getInstance(document.getElementById("swapModal")).hide();
        notify(`Skill Swap request sent to ${selectedStudent.name}! They will be notified.`);
    };
});
