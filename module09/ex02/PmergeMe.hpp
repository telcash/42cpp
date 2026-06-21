/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:28:00 by telcash           #+#    #+#             */
/*   Updated: 2026/06/20 22:28:00 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <string>
# include <vector>

class PmergeMe
{
    private:
        struct VectorPair
        {
            int small;
            int big;
        };

        struct DequePair
        {
            int small;
            int big;
        };

        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        static int _parsePositiveInt(const std::string &value);

        static std::vector<int> _buildJacobsthalOrderVector(size_t size);
        static std::deque<int> _buildJacobsthalOrderDeque(size_t size);

        static size_t _lowerBoundVector(const std::vector<int> &values, int value);
        static size_t _lowerBoundDeque(const std::deque<int> &values, int value);
        static size_t _lowerBoundVectorPairs(const std::vector<VectorPair> &values,
                                             const VectorPair &value);
        static size_t _lowerBoundDequePairs(const std::deque<DequePair> &values,
                                            const DequePair &value);

        static void _sortVectorPairs(std::vector<VectorPair> &values);
        static void _sortDequePairs(std::deque<DequePair> &values);

    public:
        static std::vector<int> parse(int argc, char **argv);
        static void sortVector(std::vector<int> &values);
        static void sortDeque(std::deque<int> &values);
        static void printSequence(const std::string &label,
                                  const std::vector<int> &values);
};

#endif
