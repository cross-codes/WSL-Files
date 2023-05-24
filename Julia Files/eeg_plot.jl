using Plots, StatsBase, MAT

function mean(arr)
    return sum(arr) / length(arr)
end

# Define the EEG signal (eeg) and other required variables
eeg = [1, 2, 3, 4, 5]

function crosscorr(x, y)
    lx, rxx, lags = length(x), AbstractFloat[], Integer[]
    x = vcat(zeros(lx - 1), x, zeros(lx - 1))
    lags_ranges = [(k - lx, k:k+lx-1) for k = 1:2*lx-1]

    foreach(lags_ranges) do (lag, range)
        push!(rxx, mean(x[range] .* y))
        push!(lags, lag)
    end
    return rxx, lags
end

N, fs = length(eeg), 50  # Length, sampling frequency of data
t = (0:N-1) / fs  # Time vector from 0 (approx.) to 2 sec.
freqs = 1:0.5:25
refs = [cos.(2π .* f .* t) for f = freqs]  # Reference signals
result = zip(refs, map(x -> crosscorr(eeg, x), refs))

max_corr, max_corr_M = [], []
foreach(result) do (ref, (rxx, lags))
    push!(max_corr, maximum(rxx))
    push!(max_corr_M, maximum(crosscov(eeg, ref, lags, demean=false)))
end

xlabel = "Reference Signal Frequency (Hz)"
ylabel = "Max correlation"
plot(freqs, max_corr, label="Manual", xlabel=xlabel, ylabel=ylabel)
plot!(freqs, max_corr_M, markershape=:circle, ls=:dot, label="StatsBase")
savefig("output.png")
