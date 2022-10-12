//
//  ProfileViewController.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 19/09/22.
//

import Foundation
import UIKit
import FirebaseAuth

class ProfileViewController: UIViewController {
    @IBOutlet weak var emailField: UIView!
    
    @IBOutlet weak var email: UILabel!
    @IBOutlet weak var exitButtonEdit: DefaultButton!
    
    
    
    override func viewDidLoad() {
        setupFirstField()
        exitButtonEdit.configure(whatsInside: "Sair")
        
        let user = Auth.auth().currentUser
        if let user = user {
            _ = user.email
        }
        email.text = user?.email
    }
    
    func setupFirstField() {
        emailField.layer.cornerRadius = 20
        emailField.layer.borderWidth = 0.5
        emailField.layer.borderColor = UIColor(red: 0.669, green: 0.669, blue: 0.669, alpha: 1).cgColor
    }
    
    @IBAction func exitButton(_ sender: Any) {
        do {
            try Auth.auth().signOut()
            tabBarController?.selectedIndex = 1
        } catch let signoutError {
            let alert = UIAlertController(title: "Erro", message: signoutError.localizedDescription, preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: "Ok", style: .destructive, handler: nil))
            self.present(alert, animated: true)
        }
        
        
    }
}
