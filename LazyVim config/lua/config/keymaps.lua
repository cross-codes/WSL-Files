-- Keymaps are automatically loaded on the VeryLazy event
-- Default keymaps that are always set: https://github.com/LazyVim/LazyVim/blob/main/lua/lazyvim/config/keymaps.lua
-- Add any additional keymaps here

local Util = require("lazyvim.util")
local wk = require("which-key")

-- Telescope plugin
vim.keymap.set(
  "n",
  "<leader>sx",
  require("telescope.builtin").resume,
  { noremap = true, silent = true, desc = "Resume Telescope" }
)

-- LaTeX plugin
vim.keymap.set("n", "<leader>m", '<cmd>:lua require("nabla").popup()<cr>', { desc = "View LaTeX expression" })

-- Competitive Coding plugin
wk.register({ ["<A>"] = { name = "+Competitive coding" } })
vim.keymap.set("n", "<A-1>", "<cmd>CphReceive <cr>", { desc = "Receive test cases [CC]" })
vim.keymap.set("n", "<A>2", "<cmd>CphTest <cr>", { desc = "Use testcases against code [CC]" })

-- Neotree plugin
vim.keymap.set("n", "<leader>p", "<cmd>Neotree ~ reveal<cr>", { desc = "Explorer NeoTree (~)" })

-- Alpha plugin
vim.keymap.set("n", "<leader>a", "<cmd>1,$bd!<cr><cmd>Alpha<cr>", { desc = "Return to dashboard" })

-- Gitignore plugin
vim.keymap.set("n", "<leader>gi", "<cmd>Gitignore<cr>", { desc = "Create sample .gitignore file" })

-- Terminal plugin
if Util.has("toggleterm.nvim") then
  wk.register({
    ["<leader>t"] = { name = "+terminal" },
  })
  vim.keymap.set("n", "<leader>tf", "<cmd>ToggleTerm direction=float<cr>", { desc = "ToggleTerm float" })
  vim.keymap.set(
    "n",
    "<leader>th",
    "<cmd>ToggleTerm size=12 direction=horizontal<cr>",
    { desc = "ToggleTerm horizontal split" }
  )
  vim.keymap.set(
    "n",
    "<leader>tv",
    "<cmd>ToggleTerm size=80 direction=vertical<cr>",
    { desc = "ToggleTerm vertical split" }
  )
  vim.keymap.set("n", "<leader>t<tab>", "<cmd>ToggleTerm direction=tab<cr>", { desc = "ToggleTerm tab" })
end
